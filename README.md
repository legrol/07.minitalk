![Descripción](https://img.shields.io/badge/Descripción-blue?style=for-the-badge)

- Proyecto **minitalk** de 42: comunicación entre procesos cliente–servidor mediante señales UNIX (`SIGUSR1` y `SIGUSR2`).  
- El cliente envía un mensaje carácter a carácter al servidor, codificando cada bit en señales.  
- El servidor recibe esas señales, reconstruye el mensaje y lo imprime en pantalla.  
- Refuerza conceptos de manejo de señales (`sigaction`), IPC y control de bits.


![Instrucciones Generales](https://img.shields.io/badge/Instrucciones%20Generales-green?style=for-the-badge)

- **Sin variables globales** (salvo estáticas internas si es imprescindible).  
- El **servidor** no recibe argumentos; al arrancar imprime su PID y espera señales.  
- El **cliente** recibe **dos** argumentos:
  1. PID del servidor.  
  2. Cadena de texto a enviar (entre comillas).  
- Cada carácter se envía bit a bit:
  - `SIGUSR1` → bit `1`  
  - `SIGUSR2` → bit `0`  
- El servidor debe configurar un handler con `sigaction` para reconstruir el byte.  
- El cliente debe pausar (`usleep` o similar) si es necesario para no saturar señales.

![Instrucciones Mandatory](https://img.shields.io/badge/Instrucciones%20Mandatory-green?style=for-the-badge)

- Implementar `server.c` y `client.c` como procesos separados.  
- El servidor imprime su PID y espera indefinidamente.  
- Al recibir 8 señales, reconstruye un carácter y lo muestra por `write(1, &c, 1)`.  
- Tras el carácter nulo (`'\0'`), el servidor puede imprimir un salto de línea.  
- El cliente debe enviar también el byte `0x00` para indicar fin de mensaje.

![⭐ Instrucciones Bonus](https://img.shields.io/badge/⭐%20Instrucciones%20Bonus-yellow?style=for-the-badge)

- El servidor envía **acuse de recibo** (`SIGUSR1`) al cliente tras recibir cada byte completo.  
- Permitir múltiples clientes:
  - Gestionar concurrencia o encolar peticiones según PID.  
- Mostrar en servidor conteo de bytes o clientes atendidos.

![Estructura del Proyecto](https://img.shields.io/badge/Estructura%20del%20Proyecto-orange?style=for-the-badge)

```text
07.minitalk-main/
├── includes/          
│   └── minitalk.h       # Prototipos y constantes
├── srcs/              
│   ├── server.c         # Lógica del servidor
│   ├── client.c         # Lógica del cliente
│   ├── utils.c          # Helpers (ft_strlen, ft_itoa, etc.)
│   └── …
├── tests/               # (Opcional) Scripts de prueba
├── Makefile             # Reglas de compilación
└── server, client       # Ejecutables resultantes
```

![Compilación](https://img.shields.io/badge/Compilación-blue?style=for-the-badge)

- make

- make all — Compila get_next_line.c y get_next_line_utils.c, genera libgnl.a.

- make clean — Elimina los objetos intermedios (*.o).

- make fclean — Además de clean, elimina libgnl.a.

- make re — Ejecuta fclean y luego all.

![Uso](https://img.shields.io/badge/Uso-yellow?style=for-the-badge)

1. Arranca el servidor:
   
    `./server`

2. Verás algo como:

    `Server PID: 12345`

2. En otra terminal, envía un mensaje:

    `./client 12345 "¡Hola desde minitalk!"`

3. El servidor mostrará:

    `¡Hola desde minitalk!`







![Autor](https://img.shields.io/badge/Autor-red?style=for-the-badge)

- Roberto del Olmo Lima
- [![GitHub](https://img.shields.io/badge/GitHub-Profile-informational?style=for-the-badge&logo=github&logoColor=white&color=181717)](https://github.com/legrol)
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/roberto-del-olmo-731746245)
