Descripción del Proyecto

Este programa es un keylogger básico escrito en C que captura y registra las pulsaciones de teclas en un archivo de texto. Utiliza la API de Linux para leer los eventos del teclado desde un dispositivo de entrada específico. Las teclas presionadas se guardan en un archivo de log para su posterior análisis.

Instrucciones de Uso

    Compilación:

    Para compilar el programa, necesitas un compilador de C. Abre una terminal y navega hasta el directorio donde se encuentra el archivo fuente (keylogger.c). Luego, ejecuta el siguiente comando:

    gcc -o keylogger keylogger.c

    Esto  generará un archivo ejecutable llamado keylogger.

    Ejecución:

    Para ejecutar el programa, necesitas permisos de superusuario, ya que requiere acceso a los dispositivos de entrada:

    sudo ./keylogger

    El programa comenzará a registrar las teclas presionadas en un archivo de log ubicado en /tmp/keylogger.txt.

    isualización del Log:

    Para visualizar el contenido del archivo de log, puedes usar cualquier editor de texto o ejecutar:

    cat /tmp/keylogger.txt

    Esto mostrará todas las teclas que han sido registradas hasta el momento.

Supuestos del Programa

    Acceso a Dispositivo de Entrada:
    El programa asume que el teclado está mapeado al dispositivo /dev/input/event7. Si este no es el caso, deberás identificar el dispositivo correcto para tu teclado usando el siguiente comando:

    ls /dev/input/

    Luego, puedes cambiar el valor de path_keyboard en el código fuente al dispositivo correcto.

  Permisos de Ejecución:

    El programa debe ser ejecutado con permisos de superusuario (sudo), ya que accede directamente al hardware del teclado, lo cual no es posible sin los permisos adecuados.

  Entorno Linux:

    Este programa está diseñado para ejecutarse en sistemas basados en Linux. No funcionará en otros sistemas operativos sin modificaciones significativas.

    Casos de Uso

        Monitoreo de Actividad en Sistemas Privados:
            Administradores de sistemas pueden usar este programa para monitorizar la actividad de teclas en sistemas privados o aislados con fines de auditoría.
            Importante: El uso de keyloggers en sistemas sin el consentimiento del usuario es ilegal en muchas jurisdicciones. Asegúrate de cumplir con las leyes locales y obtener los permisos necesarios antes de implementar este programa.

        Análisis Forense:
            En un contexto de ciberseguridad, este keylogger puede ser utilizado para capturar la secuencia de pulsaciones de teclas durante una investigación forense en sistemas comprometidos.

        Desarrollo y Pruebas:
            Desarrolladores pueden usar el código como base para entender cómo funcionan los dispositivos de entrada en Linux o como parte de proyectos educativos en seguridad informática.

Notas Importantes

      Responsabilidad Legal:
        El uso de este software con fines maliciosos está prohibido y puede ser considerado ilegal. El desarrollador no se hace responsable del mal uso del software.

      Limitaciones:
            El keylogger no captura combinaciones de teclas (e.g., Ctrl+C).
            No distingue entre mayúsculas y minúsculas si se presiona la tecla Shift.
            No registra eventos de mouse o de otros dispositivos de entrada.

      Seguridad:
        Asegúrate de proteger el archivo de log (/tmp/keylogger.txt) para evitar que sea accesible a personas no autorizadas. Considera mover el archivo a un directorio más seguro o cifrar su contenido.

Nota:
  Para poder tomar capturas debera instalar scrot 

    Créditos

    Desarrollado por Luis Enrique Solis Rocha.

    Si tienes preguntas o sugerencias, puedes contactarme a través de luissolis45@aragon.unam.mx
