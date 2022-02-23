#include "pch.h"
#include "CppUnitTest.h"
#include"../MACHINES4FUN/Ingreso.h"
#include"../MACHINES4FUN/ListaDobleCircular.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(Ingreso)
	{
	public:
		TEST_METHOD(method1)
		{

			TEST_METHOD(TestMethod1)
			{
				Assert::AreEqual(12, Ingreso::ingresoNumero("12"));
			}
			TEST_METHOD(TestMethod2)
			{
				std::string mensage = "Hola";
				Assert::AreEqual(true, Ingreso::ingresoCadena(mensage))
			}
		}
	};

	TEST_CLASS(ListaDobleCircular)
	{
		TEST_METHOD(Mmethod2)
		{
			TEST_METHOD(buscarPosicionMaquinaId)
			{
				int a;
				int b = 22;
				ListaDobleCircular lista;
				lista.insertarInicio(22);
				a = lista.buscarPosicionMaquinaId(0);
				Assert::AreEqual(a, b);
			}
		}
	};
}
