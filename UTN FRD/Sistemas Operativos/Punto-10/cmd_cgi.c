#define _GNU_SOURCE  // habilita funciones como strcasestr() etc
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

void inicio();
void fin();
int extraer(char *destino,int largo,const char *tag,char *buffer);
int esHexa(char c);
char charHexa(char *p);
int obtenercgi(char *destino,int largo);

int main(int argc, char **argv) {
	FILE *fp;
	char cmdargs[2048],cmdlinux[2048],args[1024], cmd[1024],linea[1024];
	
	inicio();
	
	memset(cmdargs,0,2048);
	int rc = obtenercgi(cmdargs,2048);
	printf("obtenercgi retorna %d metodo [%s]\n",rc,getenv("REQUEST_METHOD"));
	
	extraer(args,1024,"args",cmdargs);
	printf("args=[%s]\n",args);
	
	extraer(cmd,1024,"cmd",cmdargs);
	printf("cmd=[%s]\n",cmd);
	
	printf("<pre>cmd=%s</pre><br>\n",cmd);
	printf("<pre>args=%s</pre><br>\n",args);
	printf("<pre>\n");
	
	snprintf(cmdlinux,2048,"%s %s",cmd,args);
	
	/* Leer la salida de un comando */
	fp = popen(cmdlinux, "r");
	if (fp != NULL) {
		/* Leo lineas de salida del comando */
		while (fgets(linea, 1024, fp) != NULL) {
			int i=0;
			while(linea[i]) {
				if ( linea[i] == '<' ) printf("&#60;");
				else if ( linea[i] == '>' ) printf("&#62;");
				else printf("%c",linea[i]);
				i++;
			}
		}
		pclose(fp);
	} else { // error
		printf("Error intentado ejecutar [%s]\n",cmd);
	}
	printf("</pre>\n");

	fin();
  return 0;
}

void inicio() {
	printf("Content-Type: text/html\r\n\r\n");
	printf("<!DOCTYPE html><HTML><TITLE>Procesos</TITLE>\n<BODY>\n");
}
void fin() {
	printf("</BODY></HTML>\n");
}

/**
 * Ojo con los espacios intermedios, se reemplazan por +
 * Ojo con mayusculas y minusculas
 * buffer contiene:   variable1=valor1&variable2=valor2....
 * 
 * Toma buffer, busca tag y copia valor en destino
 * destino tiene que tener espacio suficiente
 */
int extraer(char *destino,int largo,const char *tag,char *buffer) {
	char *p = strcasestr(buffer,tag), *out = destino;
	int n=0;
	if ( p ) {
		p+=strlen(tag)+1;
		if ( *p ) {
			while(*p && *p != '&' && n < largo) {
				if (*p == '\n' || *p == '\r' || *p == '\t') { p++;continue; }
				if (*p == '+'){ *out = ' '; }
				else {
					// posible caracter codificado %00 .. %FF
					if (*p == '%' && esHexa(*(p+1)) && esHexa(*(p+2)) ) {
						*out = charHexa(p);
						p+=2;
					} else {
						*out = *p;
					}
				}
				out++;p++;n++;
			}
			*out='\0';
			return 1;
		}
	}
	return 0;
}

/**
 * Devuelve 1 (verdad) si c es un digito hexadecimal
 * Sino devuelve 0 (falso)
 */
int esHexa(char c) {
	char c2 = (char) toupper(c);
	if ( c2 >= '0' && c2 <= '9' ) return 1;
	if ( c2 >= 'A' && c2 <= 'F' ) return 1;
	return 0;
}
/**
 * p apunta a "%2A..." por ejemplo, esta funcion devuelve
 * el caracter ascii del valor hexa 2A
 */
char charHexa(char *p) {
	char hexa[3];
	hexa[0] = *(p+1);
	hexa[1] = *(p+2);
	hexa[2] = '\0';
	return (char) strtol(hexa,NULL,16);
}

/**
 * Esta funcion obtiene el string cgi cargado por el servidor
 * web para luego ser procesado
 * Puede tratarse de una llamada de tipo GET o POST
 * GET el string cgi se encuentra en variable QUERY_STRING
 * POST el string se ingresa por teclado
 * Esta funcion sirve para ambos casos
 * Retorna 1 si todo Ok
 * Retorna 0 si hubo error
 */
int obtenercgi(char *destino,int largo) {
	if ( getenv("QUERY_STRING") == NULL ) return 0;
	if ( getenv("REQUEST_METHOD") == NULL ) return 0;
	if ( strcasecmp(getenv("REQUEST_METHOD"),"GET") == 0 ) { // es GET
		if ( strlen(getenv("QUERY_STRING")) > largo ) {
			// el contenido de query_string supera a largo!
			return 0;
		}
		strcpy(destino,getenv("QUERY_STRING"));
	} else { // es POST
		int lei = read(STDIN_FILENO,destino,largo-1);
		if ( lei >= 0 ) destino[lei]='\0';
	}
	return 1;
}
