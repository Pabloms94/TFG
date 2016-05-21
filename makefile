#compilador
CC = gcc
#Flags (g->generar información debug, c->compilar sin enlazar, OX->Nivel de optimazación (de 0 a 3))
FLAGS = -g -c
#Opciones de enlazado con bibliotecas
LDFLAGS = -lm

#Directorio con fuentes del programa
SOURCEDIR = src
#Directorio con cOdigo de tests
TESTDIR= test
#Archivo doxyfile para generar documentaciOn
DOXYFILE = integralesV2.Doxyfile

#directorio donde se guardarAn los objetos y ejecutables
BUILDDIR = build
#directorio donde se guardarA la documentaciOn
DOCDIR = doc

#nombre del ejectuble
EXECUTABLE = a
#nombre del ejecutable con los tests
TESTEXECUTABLE = aTests

#Lista de ficheros fuente...
SOURCES = $(wildcard $(SOURCEDIR)/*.c)
#... y sus correspondientes .o
OBJECTS = $(patsubst $(SOURCEDIR)/%.c,$(BUILDDIR)/%.o,$(SOURCES))
#Lo mismo con fuentes para tests
TESTSOURCES = $(wildcard $(TESTDIR)/*.c)
TESTOBJECTS = $(patsubst $(TESTDIR)/%.c,$(BUILDDIR)/%.o,$(TESTSOURCES))
#Archivos objeto que se usarAn con los tests. TIpicamente todos menos el que tenga el main, revisar segUn sea el caso
OBJECTSFORTESTS = $(filter-out $(BUILDDIR)/main.o,$(OBJECTS))


#comportamiento por defecto: generar ejecutable y tests
all: dir $(BUILDDIR)/$(EXECUTABLE) $(BUILDDIR)/$(TESTEXECUTABLE)

dir:
	mkdir -p $(BUILDDIR)

#se puede pedir generar documentaciOn con make doc	
doc:
	doxygen $(DOXYFILE)

#Recordemos que $@ designa el objetivo y $^ todos los requisitos
$(BUILDDIR)/$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^
	
$(BUILDDIR)/$(TESTEXECUTABLE): $(OBJECTSFORTESTS) $(TESTOBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

#Recordemos que $< designa el primer requisito
$(OBJECTS): $(BUILDDIR)/%.o : $(SOURCEDIR)/%.c
	$(CC) $(FLAGS) $< -o $@
	
$(TESTOBJECTS): $(BUILDDIR)/%.o : $(TESTDIR)/%.c
	$(CC) $(FLAGS) $< -o $@
	

clean:
	rm -f $(BUILDDIR)/*o $(BUILDDIR)/$(EXECUTABLE) $(BUILDDIR)/$(TESTEXECUTABLE)
	rm -rf $(DOCDIR)
	
#Nombres especiales
.PHONY: clean all dir doc