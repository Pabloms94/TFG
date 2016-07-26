# X-pectra
Programa en lenguaje C que contendrá todos los cálculos numéricos para generar modelos de fuentes de rayos X, concretamente con ánodos de tungsteno.

##Preparación
* Necesitaremos descargar el directorio src, el cual contiene todos los ficheros fuente y de cabecera.
* La carpeta data, que contiene los ficheros .csv con todos los datos que podrá usar la aplicación.
* El makefile, archivo con el cual compilaremos nuestro programa.
* Por último el archivo de configuración de doxyfile si queremos que nos cree la documentación que adjuntó en el código el programador.

##Requisitos del sistema
No es necesario ningún requisito especial.

##Instalación
1. Crearemos una carpeta que podemos llamar X-pectra, por ejemplo. Aquí reuniremos todo lo necesario para el funcionamiento completo de la aplicación. El nombre no es importante.
  1. En ella tendremos que crear 2 carpetas: 
    * Una para la parte de C, en la que estamos. La llamaremos XpectraC.
    * La otra para la parte de Java. La llamaremos XpectraJ.
  1. En la carpeta llamada XpectraC colocaremos todo el contenido nombrado anteriormente en la sección de preparación.
  1. En la carteta XpectraJ introduciremos toda la parte de la interfaz en Java, situada en el repositorio "Interfaz".

![ScreenShot](/Images/1.png)

![ScreenShot](/Images/2.png)

2. Hecho ésto, podemos ejecutar el comando make desde nuestra terminal situada en el directorio ../X-pectra/XpectraC. De esta manera se nos creará automáticamente una carpeta llamada build que contendrá todos los objetos creados y el ejecutable. 

![ScreenShot](/Images/3.png)

3. Si deseamos ejecutar el programa por linea de comando basta con entrar a dicha carpeta (build), y utilizar el comando de ejecución:
  3. XpectraC.exe + 5 argumentos:
    * E0: referente al valor máximo sobre el cual calcularemos nuestro espectro.
    * Theta: ángulo en grados.
    * Phi: ángulo en grados.
    * Ey: valor mínimo del intervalo donde calcularemos el espectro.
    * Intervalo: unidades que separarán un valor de X del siguiente.
  3. Si lo hacemos correctamente, se generarán dos ficheros en formato JSON con los valores de la función (X, Y).

![ScreenShot](/Images/4.png)

![ScreenShot](/Images/5.png)

![ScreenShot](/Images/6.png)

##Tests
Si queremos ver los test que ha ido realizando el programador para comprobar la funcionalidad de ciertas partes del código, podemos descargar también la carpeta test e incluirla junto con las otras. El makefile nos generará un ejecutable llamado XpectraTests, que podríamos ejecutar desde la terminal.
Si queremos saber más acerca de ellos, se han realizado haciendo uso del framework "CuTest".
Un ejemplo de test es el siguiente:
```
void TestIntegralBasica(CuTest* tc) {
	double menor1 = 1;
	double mayor1 = 2;
	double menor2 = 3;
	double mayor2 = 4;
	double resultado;


	resultado = dobleIntegral(fuente, mayor1, menor1, mayor2, menor2);

	CuAssertDblEquals(tc, 5.25, resultado, eps);
}
```

En él se observa la definición de variables y la llamada a una función "dobleIntegral" que será la que se pruebe.
El resultado se comprobará en la última linea de código indicándole los que tiene que devolver, y con cuantas cifras decimales ha de ser exacto. En la misma terminal te informará sobre el estado satisfactorio o, de lo contraio, de su fallo y de dónde está el error.

##Herramientas usadas
Se ha trabajado con el IDE de Eclipse, el framework "CuTest" antes nombrado, y doxygen como herramienta de generación de documentación.

##Autor
Pablo Martín Sánchez

##Tutores
Guillermo Hernández

María Belén Pérez Lancho

##License
