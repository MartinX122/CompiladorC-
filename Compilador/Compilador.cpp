#include "Compilador.h"

#include <iostream>
#include <string>

using namespace System;
using namespace std;

namespace AnalizadorLexico
{
	
	/*Constructores*/
	AnalizadorLexico::AnalizadorLexico()
	{
		this->Reservar(gcnew Palabra("if", Etiqueta::IF));
		this->Reservar(gcnew Palabra("else", Etiqueta::ELSE));
		this->Reservar(gcnew Palabra("while", Etiqueta::WHILE));
		this->Reservar(gcnew Palabra("do", Etiqueta::DO));
		this->Reservar(gcnew Palabra("break", Etiqueta::BREAK));
		this->Reservar(Palabra::True);
		this->Reservar(Palabra::False);
		
		
		this->Reservar(Simbolos::Tipo::Char);
		this->Reservar(Simbolos::Tipo::Int);
		this->Reservar(Simbolos::Tipo::Bool);
		this->Reservar(Simbolos::Tipo::Float);
		
	}

	
	/*Metodos*/
	
	int Token::GetEtiqueta()
	{
		return this->etiqueta;
	}

	String^ Token::ToString() { return String::Format("{0}", this->etiqueta); }

	int Num::GetValue()
	{
		return this->valor;
	}

	String^ Num::ToString() { return String::Format("{0}", this->valor); }

	String^ Palabra::ToString()  { return this->lexema; }

	float Real::GetValue()
	{
		return this->valor;
	}

	String^ Real::ToString() { return String::Format("{0}", this->valor); }

	
	

	//int AnalizadorLexico::GetLinea() { return this->linea; }

	void AnalizadorLexico::Reservar(Palabra^ w)
	{
		this->palabras->Add(w->ToString(), w);
	}



	void AnalizadorLexico::SetCadenaLectura(String^ cadenaLectura) 
	{
		this->CadenaLectura = cadenaLectura;
	}
	
	void AnalizadorLexico::Readch()
	{
		
		

		this->preanalisis = this->CadenaLectura[this->index];
		this->index++;

		
	}


	bool AnalizadorLexico::Readch(char c)
	{
		this->Readch();
		return (this->preanalisis == c);

	}

	Token^ AnalizadorLexico::Explorar()
	{
		while ( true ) {

			this->Readch();
			
			if (this->preanalisis == ' ' || this->preanalisis == '\t')
			{
				continue;
			}
			else if (this->preanalisis == '\n')
			{
				this->linea++;
			}
			else
			{
				break;
			}

		}

		switch (this->preanalisis)
		{

		case '&':
			if (Readch('&'))
			{
				
				return Palabra:: and;
				
			}
			else
			{
				this->index--;
				return gcnew Token('&');
			}
			break;

		case '|':
			if (Readch('|'))
			{
				
				return Palabra:: or ;
			}
			else
			{
				this->index--;
				return gcnew Token('|');
			}
			break;

		case '=':
			if (Readch('='))
			{
				Readch();
				return Palabra::eq;
				

			}
			else
			{
				return gcnew Token('=');
			}
			break;

		case '!':
			if (Readch('='))
			{
				return Palabra::ne;
			}
			else
			{
				this->index--;
				return gcnew Token('!');
			}
			break;

		case '<':
			if (Readch('='))
			{
				return Palabra::le;
			}
			else
			{
				this->index--;
				return gcnew Token('<');
			}
			break;

		case '>':
			if (Readch('='))
			{
				
				return Palabra::ge;
				
			}
			else
			{
				this->index--;
				return gcnew Token('>');
			}
			break;

		}

		if (Char::IsDigit(this->preanalisis)) {

			String^ cadena = "";
			do
			{
				cadena += this->preanalisis;
				this->Readch();

			} while (Char::IsDigit(this->preanalisis) || (this->preanalisis == '.' && !cadena->Contains(".")));

			this->index--;

			if (cadena->Contains(".")) {
				return gcnew Real(float::Parse(cadena));
			}
			else
			{
				return gcnew Num(int::Parse(cadena));
			}

		}

		if (Char::IsLetter(this->preanalisis))
		{
			string cs = "";

			do
			{
				cs=cs+(char)this->preanalisis;
				this->Readch();

			} while (Char::IsLetterOrDigit(this->preanalisis));

			this->index--;
			String^ s = gcnew String(cs.c_str());

			Palabra^ w = (Palabra^)this->palabras[s];
			if (w != nullptr) return w;
			
			w = gcnew Palabra(s, Etiqueta::ID);
			this->palabras->Add(s, w);
			
			return w;
			
		}
		else {
			Token^ tok = gcnew Token(this->preanalisis);
			return tok;
		}

		

		throw gcnew LexicoException(this->linea);
		return nullptr;
	}



	String^ LexicoException::ToString()
	{
		return this->Message+this->Linea;
	}

	int LexicoException::GetLinea()
	{
		return this->Linea;
	}

}

namespace Simbolos {


	int Tipo::GetAnchura()
	{
		return this->Anchura;
	}

	bool Tipo::Numerico(Tipo^ p)
	{
		return (p == Tipo::Char || p == Tipo::Int || p == Tipo::Float);
	}

	Tipo^ Tipo::Max(Tipo^ p1, Tipo^ p2)
	{
		if (!Tipo::Numerico(p1) || !Tipo::Numerico(p2)) return nullptr;
		else if (p1 == Tipo::Float || p2 == Tipo::Float) return Tipo::Float;
		else if (p1 == Tipo::Int || p2 == Tipo::Int) return Tipo::Int;
		else return Tipo::Char;
	}

}

namespace Simbolos
{
	Ent::Ent(Ent^ a) : ant(a)
	{
		this->tabla = gcnew Hashtable();

	}




	void Ent::Put(Token^ w, Inter::Id^ i)
	{
		this->tabla->Add(w, i);
	}


	
	Inter::Id^ Ent::Get(Token^ w)
	{
		Ent^ tempEnt = this;
		do{

			Inter::Id^ encontro = (Inter::Id^)tempEnt->tabla[w];

			if (encontro != nullptr) return encontro;
			
			tempEnt = tempEnt->ant;

		} while (tempEnt != nullptr);

		return nullptr;
	}
	


	Tipo^ Arreglo::GetDE()
	{
		return this->de;
	}

	String^ Arreglo::ToString()
	{
		return "[" + this->Tamanno + "]" + de->ToString();
	}
}

namespace Inter
{

	Arit::Arit(AnalizadorLexico::Token^ tok, Expr^ x1, Expr^ x2) : Op(tok, nullptr), expr1(x1), expr2(x2)
	{
		this->SetTipo(Simbolos::Tipo::Max(expr1->GetTipo(), expr2->GetTipo()));
		if (this->GetTipo() == nullptr) this->Error("Error de Tipo");

	}

	Expr^ Arit::Gen()
	{
		return gcnew Arit(this->GetOP(),this->expr1->Reducir(),this->expr2->Reducir());
	}

	String^ Arit::ToString()
	{
		return expr1->ToString() + " " + this->GetOP()->ToString() + " " + this->expr2->ToString();
	}

	void Nodo::Error()
	{
		throw gcnew AnalizadorLexico::LexicoException(this->linealex);
	}

	void Nodo::Error(String^ Mensaje)
	{
		throw gcnew AnalizadorLexico::LexicoException(Mensaje,this->linealex);
	}

	int Nodo::NuevaEtiqueta()
	{
		return this->etiquetas++;
	}

	void Nodo::EmitirEtiqueta(int i)
	{
		Codigo::CodigoIntermedio += "L" + i + ":";

	}

	void Nodo::Emitir(String ^ s)
	{
		Codigo::CodigoIntermedio += "\t" + s;
	}



	Expr^ Expr::Gen()
	{
		return this;
	}

	Expr^ Expr::Reducir()
	{
		return this;
	}

	void Expr::Salto(int t, int f)
	{
		this->EmitirSalto(this->ToString(), t, f);
	}

	void Expr::EmitirSalto(String ^ prueba, int t, int f)
	{

		if (t != 0 && f != 0) {
			this->Emitir("if " + prueba + " goto L" + t);
			this->Emitir("goto L" + f);
		}
		else if (t != 0) this->Emitir("if " + prueba + " goto L" + t);
		else if (f != 0) this->Emitir("iffalse " + prueba + " goto L" + f);

	}

	void Expr::SetTipo(Simbolos::Tipo ^ tp)
	{
		this->tipo = tp;
	}

	Simbolos::Tipo^ Expr::GetTipo()
	{
		return this->tipo;
	}

	AnalizadorLexico::Token^ Expr::GetOP()
	{
		return op;
	}

	void Expr::SetOP(AnalizadorLexico::Token^ _op)
	{
		this->op = _op;
	}

	String^ Expr::ToString()
	{
		return op->ToString();
	}

	Expr^ Op::Reducir()
	{
		Expr^ x = this->Gen();
		Temp^ t = gcnew Temp(this->GetTipo());
		this->Emitir(t->ToString() + "=" + x->ToString());
		return t;
	}


	String^ Temp::ToString()
	{
		return "t" + numero;
	}

	Unario::Unario(AnalizadorLexico::Token^ tok, Expr^ x) : Op(tok, nullptr), expr(x) 
	{
		this->SetTipo(Simbolos::Tipo::Max(Simbolos::Tipo::Int,expr->GetTipo()));
	
		if (this->GetTipo() == nullptr) Error("Error de tipo");
	}

	Expr^ Unario::Gen()
	{
		return gcnew Unario(this->GetOP(),expr->Reducir());
	}

	String^ Unario::ToString()
	{
		return this->GetOP()->ToString() + " " + expr->ToString();
	}


	void Constante::Salto(int t, int f)
	{
		if (this == this->True && t != 0) this->Emitir("goto L" + t);
		else if (this == False && f != 0) this->Emitir("goto L"+f);
	}

	Logica::Logica(AnalizadorLexico::Token^ tok, Expr^ x1, Expr^ x2) : Expr (tok, nullptr), expr1(x1), expr2(x2)
	{
		this->SetTipo(this->Comprobar(expr1->GetTipo(),expr2->GetTipo()));
	}

	Simbolos::Tipo^ Logica::Comprobar(Simbolos::Tipo^ p1, Simbolos::Tipo^ p2)
	{
		if (p1 == Simbolos::Tipo::Bool && p2 == Simbolos::Tipo::Bool) return Simbolos::Tipo::Bool;
		else return nullptr;
	}

	Expr^ Logica::Gen()
	{
		int f = this->NuevaEtiqueta();
		int a = this->NuevaEtiqueta();

		Temp^ temp = gcnew Temp(this->GetTipo());

		this->Salto(0, f);

		this->Emitir(temp->ToString() + " = true");
		this->Emitir("goto L" + a);

		this->EmitirEtiqueta(f);
		this->Emitir(temp->ToString()+" = false");
		this->EmitirEtiqueta(a);

		return temp;
	}

	String^ Logica::ToString()
	{
		return expr1->ToString() + " " + this->GetOP()->ToString() + " " + expr2->ToString();
	}

	void Or::Salto(int t, int f)
	{
		int etiqueta = t != 0 ? t : this->NuevaEtiqueta();

		this->expr1->Salto(etiqueta,0);
		this->expr2->Salto(t, f);

		if (t == 0) this->EmitirEtiqueta(etiqueta);

	}

	void And::Salto(int t, int f)
	{
		int etiqueta = f != 0 ? f : this->NuevaEtiqueta();

		this->expr1->Salto(etiqueta, 0);
		this->expr2->Salto(t, f);

		if (f == 0) this->EmitirEtiqueta(etiqueta);
	}

	void Not::Salto(int t, int f)
	{
		expr2->Salto(f, t);
	}

	String^ Not::ToString()
	{
		return this->GetOP()->ToString() + " " + expr2->ToString();
	}

	Simbolos::Tipo^ Rel::Comprobar(Simbolos::Tipo^ p1, Simbolos::Tipo^ p2)
	{
		Type^ type = Simbolos::Arreglo::typeid;

		if (type->IsInstanceOfType(p1) || type->IsInstanceOfType(p2)) return nullptr;
		else if (p1 == p2) return Simbolos::Tipo::Bool;
		else return nullptr;
		
		
	}

	void Rel::Salto(int t, int f)
	{
		Expr^ a = expr1->Reducir(), ^b = expr2->Reducir();

		String^ prueba = a->ToString() + " " + this->GetOP()->ToString() + " " + b->ToString();
		this->EmitirSalto(prueba, t, f);
	}

	Expr^ Acceso::Gen()
	{
		return gcnew Acceso(this->arreglo, this->indice->Reducir(), this->GetTipo());
	}

	void Acceso::Salto(int t, int f)
	{
		this->EmitirSalto(this->Reducir()->ToString(),t,f);
	}

	String^ Acceso::ToString()
	{
		return arreglo->ToString() + "[" + this->indice->ToString() + "]";
	}

	

	If::If(Expr^ x, Instr^ s) : expr(x),instr(s)
	{
		if (this->expr->GetTipo() != Simbolos::Tipo::Bool) expr->Error("Se requiere booleano en if");
	}

	void If::Gen(int b, int a)
	{
		int etiqueta = this->NuevaEtiqueta();
		this->expr->Salto(0, a);
		this->EmitirEtiqueta(etiqueta);
		this->instr->Gen(etiqueta, a);

	}

	Else::Else(Expr^ x, Instr^ s1, Instr^ s2) :expr(x), instr1(s1), instr2(s2)
	{
		if (expr->GetTipo() != Simbolos::Tipo::Bool) expr->Error("Se requiere booleano en if");
	}

	void Else::Gen(int b, int a)
	{
		int etiqueta1 = this->NuevaEtiqueta();
		int etiqueta2 = this->NuevaEtiqueta();

		this->expr->Salto(0, etiqueta2);

		this->EmitirEtiqueta(etiqueta1);
		this->instr1->Gen(etiqueta1, a);
		this->Emitir("goto L" + a);
		this->EmitirEtiqueta(etiqueta2);
		this->instr2->Gen(etiqueta2, a);
	}
	void While::inic(Expr^ x, Instr^ s)
	{
		expr = x;
		instr = s;

		if (expr->GetTipo() != Simbolos::Tipo::Bool) expr->Error("Se requiere Booleano en while");
	}
	void While::Gen(int b, int a)
	{
		this->despues = a;

		this->expr->Salto(0,a);

		int etiqueta = NuevaEtiqueta();
		this->instr->Gen(etiqueta, b);

		this->Emitir("goto L"+b);
	}
	void Do::inic(Expr^ x, Instr^ s)
	{
		expr = x;
		instr = s;

		if (expr->GetTipo() != Simbolos::Tipo::Bool) expr->Error("Se requiere Booleano en while");
	}
	void Do::Gen(int b, int a)
	{
		this->despues = a;

		int etiqueta = NuevaEtiqueta();
		this->instr->Gen( b,etiqueta );

		this->EmitirEtiqueta(etiqueta);

		this->expr->Salto(b,0);

	}

	Est::Est(Id^ i, Expr^ x) : id(i),expr(x)
	{
		if (this->Comprobar(id->GetTipo(), expr->GetTipo()) == nullptr) Error("error de tipo");
	}
	Simbolos::Tipo^ Est::Comprobar(Simbolos::Tipo^ p1, Simbolos::Tipo^ p2)
	{
		if (Simbolos::Tipo::Numerico(p1) && Simbolos::Tipo::Numerico(p2)) return p2;
		else if (p1 == Simbolos::Tipo::Bool && p2 == Simbolos::Tipo::Bool) return p2;
		else return nullptr;
	}


	EstElement::EstElement(Acceso^ x, Expr^ y)
	{
		if (this->Comprobar(x->GetTipo(), expr->GetTipo()) == nullptr) Error("Error de tipo");
	}

	Simbolos::Tipo^ EstElement::Comprobar(Simbolos::Tipo^ p1, Simbolos::Tipo^ p2)
	{
		Type^ type = Simbolos::Arreglo::typeid;

		if (type->IsInstanceOfType(p1) || type->IsInstanceOfType(p2)) return nullptr;
		else if (p1 == p2) return p2;
		else if (Simbolos::Tipo::Numerico(p1) && Simbolos::Tipo::Numerico(p2)) return p2;
		else return nullptr;
	}

	void EstElement::Gen(int b, int a)
	{
		String^ s1 = indice->Reducir()->ToString();
		String^ s2 = expr->Reducir()->ToString();
		this->Emitir(arreglo->ToString() + " [ " + s1 + " ] = " + s2);
	}

	void Sec::Gen(int b, int a)
	{
		if (instr1 == Instr::Null) instr2->Gen(b, a);
		else if (instr2 == Instr::Null) instr1->Gen(b, a);
		else 
		{
			int etiqueta = this->NuevaEtiqueta();
			instr1->Gen(b, etiqueta);
			this->EmitirEtiqueta(etiqueta);
			instr2->Gen(etiqueta, a);
		}

	}

	Break::Break()
	{
		if (Instr::Circundante == nullptr)
			Error("break no encerrada");
		instr = Instr::Circundante;
	}

	void Break::Gen(int b, int a)
	{
		this->Emitir("goto L" + instr->despues);
	}

}

namespace Analizador {

	Analizador::Analizador(AnalizadorLexico::AnalizadorLexico^ lx) : lex(lx)
	{
		this->Mover();
	}

	void Analizador::Programa()
	{
		Inter::Instr^ s = this->Bloque();
		int inicio = s->NuevaEtiqueta();
		int despues = s->NuevaEtiqueta();
		s->EmitirEtiqueta(inicio);
		s->Gen(inicio, despues);
		s->EmitirEtiqueta(despues);
	}

	Inter::Instr^ Analizador::Bloque()
	{
		this->Coincidir('{');
		Simbolos::Ent^ entGurdado = this->sup;
		this->sup = gcnew Simbolos::Ent(sup);
		this->Decls();
		Inter::Instr^ s = this->Instrs();
		this->Coincidir('}');
		this->sup = entGurdado;
		return s;
	}

	void Analizador::Decls()
	{
		while (busca->GetEtiqueta() == AnalizadorLexico::Etiqueta::BASIC)
		{ 
			Simbolos::Tipo^ p = Tipo(); 
			AnalizadorLexico::Token^ tok = busca;
			this->Coincidir(AnalizadorLexico::Etiqueta::ID);
			this->Coincidir(';');
			Inter::Id^ id = gcnew Inter::Id((AnalizadorLexico::Palabra^)tok, p, usado);
			sup->Put(tok, id);
			usado = usado + p->GetAnchura();
		}
	}

	Simbolos::Tipo^ Analizador::Tipo()
	{
		Simbolos::Tipo^ p = (Simbolos::Tipo^)busca; 
		this->Coincidir(AnalizadorLexico::Etiqueta::BASIC);
		if (this->busca->GetEtiqueta() != '[')
			return p; 
		else
			return this->Dims(p); 
	
	}

	Simbolos::Tipo^ Analizador::Dims(Simbolos::Tipo^ p)
	{
		this->Coincidir('['); 
		AnalizadorLexico::Token^ tok = busca; 
		this->Coincidir(AnalizadorLexico::Etiqueta::NUM); 
		this->Coincidir(']');
		if (this->busca->GetEtiqueta() == '[')
			p = this->Dims(p);
		return gcnew Simbolos::Arreglo(((AnalizadorLexico::Num^)tok)->GetValue(), p);
	}

	Inter::Instr^ Analizador::Instrs()
	{
		if (busca->GetEtiqueta() == '}')
			return Inter::Instr::Null;
		else
			return gcnew Inter::Sec(this->Instr(), this->Instrs());
	}

	Inter::Instr^ Analizador::Instr()
	{
		

		Inter::Expr^ x;
		Inter::Instr ^s, ^s1, ^s2;
		Inter::Instr ^instrGuardada; 

		switch (this->busca->GetEtiqueta())
		{
		case ';':
		{
			this->Mover();
			return Inter::Instr::Null;
		}

		case AnalizadorLexico::Etiqueta::IF:
		{
			this->Coincidir(AnalizadorLexico::Etiqueta::IF); 
			this->Coincidir('('); 
			x = this->Bool(); 
			this->Coincidir(')');
			s1 = this->Instr();
			if (this->busca->GetEtiqueta() != AnalizadorLexico::Etiqueta::ELSE) return gcnew Inter::If(x, s1);
			this->Coincidir(AnalizadorLexico::Etiqueta::ELSE);
			s2 = this->Instr();
			return gcnew Inter::Else(x, s1, s2);
		}

		case AnalizadorLexico::Etiqueta::WHILE:
		{
			
			Inter::While^ nodowhile = gcnew Inter::While();
			instrGuardada = this->Instr()->Circundante;

			this->Instr()->Circundante = nodowhile;
			this->Coincidir(AnalizadorLexico::Etiqueta::WHILE);
			this->Coincidir('(');
			x = this->Bool();
			this->Coincidir(')');
			s1 = this->Instr();
			nodowhile->inic(x, s1);
			this->Instr()->Circundante = instrGuardada;
			return nodowhile;
			
		}

		case AnalizadorLexico::Etiqueta::DO:
		{
			
			Inter::Do^ nododo = gcnew Inter::Do();
			instrGuardada = this->Instr()->Circundante; 
			this->Instr()->Circundante = nododo;
			this->Coincidir(AnalizadorLexico::Etiqueta::DO);
			s1 = this->Instr();
			this->Coincidir(AnalizadorLexico::Etiqueta::WHILE); this->Coincidir(')'); x = this->Bool();; this->Coincidir(')');
			this->Coincidir(';');
			nododo->inic(x, s1);
			this->Instr()->Circundante = instrGuardada;
			return nododo;
			
		}

		case AnalizadorLexico::Etiqueta::BREAK:
		{

			
			this->Coincidir(AnalizadorLexico::Etiqueta::BREAK); this->Coincidir(';');
			return gcnew Inter::Break();
		}

		case '{':
		{
			return this->Bloque();
		}

		default: 
		{
			return this->Asignar();
		}

		}
	}

	Inter::Instr^ Analizador::Asignar()
	{
		Inter::Instr^ instr; 
		AnalizadorLexico::Token^ t = busca;
		this->Coincidir(AnalizadorLexico::Etiqueta::ID);
		Inter::Id^ id = sup->Get(t);
		if (id == nullptr)
		{
			Error(t->ToString() + " no declarado");
		}
		if (busca->GetEtiqueta() == '=')
		{ 
			this->Mover(); 
			instr = gcnew Inter::Est(id, this->Bool());
		}
		else
		{ 
			Inter::Acceso^ x = this->Desplazamiento(id);
			this->Coincidir('=');
			instr = gcnew Inter::EstElement(x, this->Bool());
		}
		this->Coincidir(';');
		return instr;
	}

	Inter::Expr^ Analizador::Bool()
	{
		Inter::Expr^ x = this->Unir();
		while (busca->GetEtiqueta() == AnalizadorLexico::Etiqueta::OR)
		{
			AnalizadorLexico::Token^ tok = busca;
			this->Mover(); 
			x = gcnew Inter::Or(tok, x, this->Unir());
		}
		return x;
	}

	Inter::Expr^ Analizador::Unir()
	{
		Inter::Expr^ x = this->Igualdad();
		while (busca->GetEtiqueta() == AnalizadorLexico::Etiqueta::AND)
		{
			AnalizadorLexico::Token^ tok = busca;
			this->Mover();
			x = gcnew Inter::And(tok, x, this->Igualdad());
		}
		return x;
	}

	Inter::Expr^ Analizador::Igualdad()
	{
		Inter::Expr^ x = this->Rel();
		while (busca->GetEtiqueta() == AnalizadorLexico::Etiqueta::EQ || busca->GetEtiqueta() == AnalizadorLexico::Etiqueta::NE)
		{
			AnalizadorLexico::Token^ tok = busca;
			this->Mover();
			x = gcnew Inter::Rel(tok, x, this->Rel());
		}
		return x;
	}

	Inter::Expr^ Analizador::Rel()
	{
		Inter::Expr^ x = this->Expr();
		AnalizadorLexico::Token^ tok;
		switch (busca->GetEtiqueta())
		{

		case '<':
		case AnalizadorLexico::Etiqueta::LE:
		case AnalizadorLexico::Etiqueta::GE:
		case '>':

			tok = busca;
			this->Mover();
			x = gcnew Inter::Rel(tok, x, this->Expr());
			
		default:
			return x;
		}
		
	}

	Inter::Expr^ Analizador::Expr()
	{
		

		Inter::Expr^ x = this->Term();
		while (busca->GetEtiqueta() == '+' || busca->GetEtiqueta() == '-')
		{
			AnalizadorLexico::Token^ tok = busca;
			this->Mover();
			x = gcnew Inter::Arit(tok, x, this->Term());
		}
		return x;
	}

	Inter::Expr^ Analizador::Term()
	{
		
		Inter::Expr^ x = this->Unario();
		while (busca->GetEtiqueta() == '*' || busca->GetEtiqueta() == '/')
		{
			AnalizadorLexico::Token^ tok = busca;
			this->Mover();
			x = gcnew Inter::Arit(tok, x, this->Unario());
		}
		return x;

	}

	Inter::Expr^ Analizador::Unario()
	{
		
		if (busca->GetEtiqueta() == '-') {
			
			this->Mover();
			return gcnew Inter::Unario(AnalizadorLexico::Palabra::minus, this->Unario());
		}
		else if (busca->GetEtiqueta() == '!') {
			AnalizadorLexico::Token^ tok = busca;
			this->Mover();
			return gcnew Inter::Not(tok, this->Unario());
		}
		else return this->Factor();
	}

	Inter::Expr^ Analizador::Factor()
	{

		Inter::Expr^ x = nullptr;
		switch (busca->GetEtiqueta())
		{
		case '(':
			this->Mover(); 
			x = Bool(); 
			this->Coincidir(')');
			return x;

		case AnalizadorLexico::Etiqueta:: NUM:
			x = gcnew Inter::Constante(busca, Simbolos::Tipo::Int); 
			this->Mover(); 
			return x;

		case AnalizadorLexico::Etiqueta::REAL:
			x = gcnew Inter::Constante(busca, Simbolos::Tipo::Float);
			this->Mover();
			return x;

		case AnalizadorLexico::Etiqueta::TRUE:
			x = Inter::Constante::True; 
			this->Mover();
			return x;

		case AnalizadorLexico::Etiqueta::FALSE:
			x = Inter::Constante::False;
			this->Mover();
			return x;

		default:
			this->Error("error de sintaxis");
			return x;
		
		case AnalizadorLexico::Etiqueta::ID:
			String^ s = busca->ToString();
			Inter::Id^ id = sup->Get(busca);

			if (id == nullptr)
				Error(busca->ToString() + " no declarado");
			this->Mover();

			if (busca->GetEtiqueta() != '[')
				return id;
			else
				return this->Desplazamiento(id);

		}
		
	}

	Inter::Acceso^ Analizador::Desplazamiento(Inter::Id^ a)
	{
		Inter::Expr ^i, ^w, ^t1, ^t2, ^ubic;
		Simbolos::Tipo^ tipo = a->GetTipo();

		this->Coincidir('['); 
		i = this->Bool(); 
		this->Coincidir(']');

		tipo = ((Simbolos::Arreglo^)tipo)->GetDE();

		w = gcnew Inter::Constante(tipo->GetAnchura());

		t1 = gcnew Inter::Arit(gcnew AnalizadorLexico::Token('*'), i, w);
		ubic = t1;

		while (busca->GetEtiqueta() == '[')
		{ 
			this->Coincidir('['); 
			i = Bool(); 
			this->Coincidir('[');

			tipo = ((Simbolos::Arreglo^)tipo)->GetDE();

			w = gcnew Inter::Constante(tipo->GetAnchura());

			t1 = gcnew Inter::Arit(gcnew AnalizadorLexico::Token('*'), i, w);
			t2 = gcnew Inter::Arit(gcnew AnalizadorLexico::Token('+'), ubic, t1);  //new Arit(new Token('+'), ubic, t1);
			ubic = t2;
		}
		return gcnew Inter::Acceso(a, ubic, tipo);
		
	}

	void Analizador::Mover()
	{
		busca = lex->Explorar();
	}

	void Analizador::Error(String ^error)
	{
		throw gcnew AnalizadorLexico::LexicoException(error);
	}

	void Analizador::Error()
	{
		throw gcnew AnalizadorLexico::LexicoException();
	}

	void Analizador::Coincidir(int t)
	{
		if (this->busca->GetEtiqueta() == t) this->Mover();
		else this->Error();
	}


};