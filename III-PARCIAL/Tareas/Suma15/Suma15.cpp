#include <iostream>


using namespace std;

int main()
{

	int solcount=0;

	cout << "\t BIENVENIDO ESTAS SON LAS POSIBLES SOLUCIONES" << endl;

	for (int a = 1; a <= 9; a++)
	{
		for (int b = 1; b <= 9; b++)
		{
			for (int c = 1; c <= 9; c++)
			{
				for (int d = 1; d <= 9; d++)
				{
					for (int e = 1; e <= 9; e++)
					{
						for (int f = 1; f <= 9; f++)
						{
							for (int g = 1; g <= 9; g++)
							{
								for (int h = 1; h <= 9; h++)
								{
									for (int i = 1; i <= 9; i++)
									{
										if (a + b + c == d + e + f) 
											if (a + b + c == g + h + i)
												if(a + b + c == a + e + i) 
													if(a + b + c == c + e +g)
														if(a + b + c == a + d +g)
															if(a + b + c == b + e +h)
																if(a + b + c == g + h + i)
																{
																	if (a != b && a != c && a != d && a != e && a != f && a != g && a != h && a != i)
																		if (b != c && b != d && b != e && b != f && b != g && b != h && b != i)
																			if (c != d && c != e && c != f && c != g && c != h && c != i)
																				if (d != e && d != f && d != g && d != h && d != i)
																					if (e != f && e != g && e != h && e != i)
																						if (f != g && f != h && f != i)
																							if (g != h && g != i)
																								if (h != i)
																								{
																									solcount++;
																									cout << a << " " << b << " " << c << endl;
																									cout << d << " " << e << " " << f << endl;
																									cout << g << " " << h << " " << i << endl << endl;

																								}
											
																}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	cout << "Existen " << solcount << " soluciones diferentes para el problema" << endl;


	return 0;
}