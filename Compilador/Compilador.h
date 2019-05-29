#include <iostream>

using namespace System::Collections;
using namespace System;

public ref  class Codigo
{
public:
	static String^ CodigoIntermedio = "";
};


namespace AnalizadorLexico 
{
	
	public enum Etiqueta 
	{
		AND = 256, 
		BASIC = 257, 
		BREAK = 258, 
		DO = 259, 
		ELSE = 260,
		EQ = 261,
		FALSE = 262,
		GE = 263, 
		ID = 264, 
		IF = 265,
		INDEX = 266, 
		LE = 267, 
		MINUS = 268, 
		NE = 269, 
		NUM = 270,
		OR = 271, 
		REAL = 272, 
		TEMP = 273, 
		TRUE = 274, 
		WHILE = 275
	};

	public ref class Token 
	{
	private:
		int etiqueta = 0;
		
	public:
		Token(int tag) : etiqueta(tag) {}
		int GetEtiqueta();
		String^ ToString() override;
	};

	public ref class Num : public Token
	{
	private:
		int valor;

	public:
		Num(int v) : Token(Etiqueta::NUM), valor(v) {}
		int GetValue();
		String^ ToString() override;

	};

	public ref class  Palabra : public Token
	{
	private:
		String^ lexema;
		

	public:
		
		Palabra(String^ valor, int etiqueta) : Token(etiqueta), lexema(valor) {}
		String^ ToString() override;
		
		static Palabra 
			^and = gcnew Palabra("&&", Etiqueta::AND),
			^or = gcnew Palabra("||", Etiqueta::OR),
			^eq = gcnew Palabra("==", Etiqueta::EQ),
			^ne = gcnew Palabra("!=", Etiqueta::NE),
			^le = gcnew Palabra("<=", Etiqueta::LE),
			^ge = gcnew Palabra(">=", Etiqueta::GE),
			^minus = gcnew Palabra("minus", Etiqueta::MINUS),
			^True = gcnew Palabra("true", Etiqueta::TRUE),
			^False = gcnew Palabra("false", Etiqueta::FALSE),
			^temp = gcnew Palabra("t", Etiqueta::TEMP);
		
	
	};

	
	public ref class Real : public Token
	{
	private:
		float valor;

	public:
		Real(float v) : Token(Etiqueta::REAL), valor(v) {}
		float GetValue();
		String^ ToString() override;
		

	};


	public ref class AnalizadorLexico {

	public:
		//int GetLinea();
		AnalizadorLexico();
		void SetCadenaLectura(String^ cadenaLectura);
		Token^ Explorar();
		static int linea = 0;


	private:
		
		int index = 0;

		String^ CadenaLectura;

		char preanalisis = '\0';
		Hashtable^ palabras = gcnew Hashtable();

		void Reservar(Palabra^ w);
		void Readch();
		bool Readch(char c);
		

	};

	public ref class LexicoException : public Exception 
	{
	private:
		int Linea = 0;
	public:
		LexicoException() : Exception("Error de sintaxis en linea "), Linea(AnalizadorLexico::AnalizadorLexico::linea) {}
		LexicoException(int linea) : Exception("Error de sintaxis en linea "), Linea(linea) {}
		LexicoException(String^ Mensaje,int linea) : Exception(Mensaje), Linea(linea) {}
		LexicoException(String^ Mensaje) : Exception(Mensaje), Linea(AnalizadorLexico::AnalizadorLexico::linea) {}
		String^ ToString() override;
		int GetLinea();

	};

}

namespace Simbolos {

	using namespace AnalizadorLexico;

	public ref class Tipo : public Palabra
	{
	private:
		int Anchura = 0;

	public:
		Tipo(String^ s, int etiqueta, int w) : Palabra(s, etiqueta), Anchura(w) {}

		int GetAnchura();

		static Tipo
			^ Int = gcnew Tipo("int", Etiqueta::BASIC, 4),
			^ Float = gcnew Tipo("float", Etiqueta::BASIC, 8),
			^ Char = gcnew Tipo("char", Etiqueta::BASIC, 1),
			^ Bool = gcnew Tipo("bool", Etiqueta::BASIC, 1);

		static bool Numerico(Tipo^ p);

		static Tipo^ Max(Tipo^ p1, Tipo^ p2);

	};
}

namespace Inter
{

	public ref class Nodo
	{
	private:
		int linealex = 0;


	public:
		Nodo() :linealex(AnalizadorLexico::AnalizadorLexico::linea) {}
		void Error();
		void Error(String^ Mensaje);

		static int etiquetas = 0;
		int NuevaEtiqueta();
		void EmitirEtiqueta(int i);
		void Emitir(String^ s);

	};

	public ref class Expr : public Nodo
	{
	private:
		AnalizadorLexico::Token^ op;
		Simbolos::Tipo^ tipo;

	public:
		Expr(AnalizadorLexico::Token^ tok, Simbolos::Tipo^ p) : op(tok), tipo(p) {}
		Expr^ Gen();
		Expr^ Reducir();
		void Salto(int t, int f);
		void EmitirSalto(String^ prueba, int t, int f);
		void SetTipo(Simbolos::Tipo^ tp);
		Simbolos::Tipo^ GetTipo();
		AnalizadorLexico::Token^ GetOP();
		void SetOP(AnalizadorLexico::Token^ _op);


		String^ ToString() override;

	};

	public ref class Id : public Expr
	{
	public:
		int desplazamiento;
		Id(AnalizadorLexico::Palabra^ id, Simbolos::Tipo^ p, int b) : Expr(id, p), desplazamiento(b) {}
	};


	public ref class Op : Expr {

	public:
		Op(AnalizadorLexico::Token^ tok, Simbolos::Tipo^ p) :Expr(tok, p) {}
		Expr^ Reducir();

	};

	public ref class Arit :public Op
	{
	private:
		Expr^ expr1, ^ expr2;


	public:
		Arit(AnalizadorLexico::Token^ tok, Expr^ expr1, Expr^ expr2);
		Expr^ Gen();
		String^ ToString() override;
	};

	public ref class Temp :public Expr {
	private:
		int numero = 0;

	public:
		static int conteo = 0;
		Temp(Simbolos::Tipo^ p) : Expr (AnalizadorLexico::Palabra::temp, p), numero(conteo++) {}
		String^ ToString() override;


	};

	public ref class Unario :public Op
	{
	public:
		Expr^ expr;
		Unario(AnalizadorLexico::Token^ tok, Expr^ x);

		Expr^ Gen();
		String^ ToString() override;

	};


	public ref class Constante  :public Expr
	{
	public:
		Constante(AnalizadorLexico::Token^ tok, Simbolos::Tipo^ p) : Expr(tok, p) {}
		Constante(int i) : Expr(gcnew AnalizadorLexico::Num(i), Simbolos::Tipo::Int) {}

		static Constante
			^True = gcnew Constante(AnalizadorLexico::Palabra::True, Simbolos::Tipo::Bool),
			^False = gcnew Constante(AnalizadorLexico::Palabra::False, Simbolos::Tipo::Bool);

		void Salto(int t, int f);
	};

	public ref class Logica : public Expr
	{
	public:
		Expr ^expr1, ^expr2;
		Logica(AnalizadorLexico::Token^ tok, Expr^ expr1, Expr^ expr2);
		Simbolos::Tipo^ Comprobar(Simbolos::Tipo^ p1, Simbolos::Tipo^ p2);
		Expr^ Gen();
		String^ ToString() override;



	};

	public ref class Or : public Logica 
	{
	public: 
		Or(AnalizadorLexico::Token^ tok, Expr^ expr1, Expr^ expr2) : Logica(tok, expr1, expr2) {}
		void Salto(int t, int f);

	};


	public ref class And : public Logica
	{
	public:
		And(AnalizadorLexico::Token^ tok, Expr^ expr1, Expr^ expr2) : Logica(tok, expr1, expr2) {}
		void Salto(int t, int f);
		
	};

	public ref class Not : public Logica 
	{
	public:
		Not(AnalizadorLexico::Token^ tok, Expr^ expr2) : Logica(tok, expr2, expr2) {}
		void Salto(int t, int f);
		String^ ToString() override;

	};

	public ref class Rel : public Logica
	{
	public:
		Rel(AnalizadorLexico::Token^ tok, Expr^ expr1, Expr^ expr2) : Logica(tok, expr1, expr2) {}
		Simbolos::Tipo^ Comprobar(Simbolos::Tipo^ p1, Simbolos::Tipo^ p2);
		void Salto(int t, int f);
		
	};


	public ref class Acceso : public Op {
	public:
		Id^ arreglo;
		Expr^ indice;

		Acceso(Id^ a, Expr^ i, Simbolos::Tipo^ p):Op(gcnew AnalizadorLexico::Palabra("[]", AnalizadorLexico::Etiqueta::INDEX),p),arreglo(a),indice(i) {}
		
		Expr^ Gen();
		void Salto(int t, int f);
		String^ ToString() override;

	};

	public ref class Instr : public Nodo {
	public:
		Instr() {}
		static Instr ^Null = gcnew Instr();
		void Gen(int b, int a) {}
		int despues = 0;
		static Instr^ Circundante = Instr::Null;
	};

	public ref class If : public Instr {
	private:
		Expr^ expr;
		Instr^ instr;

	public:
		If(Expr^ x, Instr^ s);
		void Gen(int b, int a);

	};


	public ref class Else : public Instr {
	private:
		Expr^ expr;
		Instr^ instr1, ^instr2;

	public:
		Else(Expr^ x, Instr^ s1, Instr^ s2);
		void Gen(int b, int a);

	};

	public ref class While : public Instr {
	private:
		Expr^ expr;
		Instr^ instr;

	public:
		While(void) {}

		void inic(Expr^ x, Instr^ s);
		void Gen(int b, int a);

		

	};

	public ref class Do : public Instr {
	private:
		Expr^ expr; 
		Instr^ instr;

	public:	
		Do() : expr(nullptr), instr(nullptr) {}
		void inic(Expr^ x, Instr^ s);
		void Gen(int b, int a);


	};


	public ref class Est :public Instr {

	public:
		Id^ id;
		Expr^ expr;

		Est(Id^ i, Expr^ x);


		Simbolos::Tipo^ Comprobar(Simbolos::Tipo^ p1, Simbolos::Tipo^ p2);
	};

	public ref class EstElement : public Instr
	{
	public:
		Id^ arreglo;
		Expr^ indice;
		Expr^ expr;

		EstElement(Acceso^ x, Expr^ y);

		Simbolos::Tipo^ Comprobar(Simbolos::Tipo^ p1, Simbolos::Tipo^ p2);
		void Gen(int b, int a);
	};

	public ref class Sec : public Instr {
	private:
		Instr ^instr1, ^instr2;
	
	public:
		Sec(Instr^ s1, Instr^ s2) : instr1(s1), instr2(s2) {}
		void Gen(int b, int a);

	};

	public ref class Break : public Instr
	{
	private:
		Instr^ instr;

	public:
		Break();
		void Gen(int b, int a);
	};

}

namespace Simbolos
{

	using namespace System;
	using namespace System::Collections;

	using namespace AnalizadorLexico;

	public ref class Ent
	{
	private:
		Hashtable^ tabla;

	protected:
		Ent^ ant;

	public:
		Ent(Ent^ a);

		void Put(Token^ w, Inter::Id^ i);
		Inter::Id^ Get(Token^ w);

	};

	public ref class Arreglo : public Tipo {

	private:
		Tipo^ de;
		int Tamanno = 1;

	public:
		Arreglo(int tm, Tipo^ p) : Tamanno(tm), de(p), Tipo("[]", Etiqueta::INDEX, tm* p->GetAnchura()) {}
		Tipo^ GetDE();
		String^ ToString() override;
		

	};


}

namespace Analizador {

	public ref class Analizador {

	private:
		AnalizadorLexico::AnalizadorLexico^ lex;
		AnalizadorLexico::Token^ busca;
		Simbolos::Ent^ sup = nullptr;
		int usado = 0;

		void Mover();
		void Error(String ^error);
		void Error();
		void Coincidir(int t);
		Inter::Instr^ Bloque();
		void Decls();
		Simbolos::Tipo^ Tipo();
		Simbolos::Tipo^ Dims(Simbolos::Tipo^ p);
		Inter::Instr^ Instrs();
		Inter::Instr^ Instr();
		Inter::Instr^ Asignar();
		Inter::Expr^ Bool();
		Inter::Expr^ Unir();
		Inter::Expr^ Igualdad();
		Inter::Expr^ Rel();
		Inter::Expr^ Expr();
		Inter::Expr^ Term();
		Inter::Expr^ Unario();
		Inter::Expr^ Factor();
		Inter::Acceso^ Desplazamiento(Inter::Id^ id);

	public:
		Analizador(AnalizadorLexico::AnalizadorLexico^ lx);
		void Programa();
		

	};

};