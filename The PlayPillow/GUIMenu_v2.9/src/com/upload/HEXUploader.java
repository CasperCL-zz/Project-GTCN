package com.upload;

import com.view.Menu;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import javax.swing.JOptionPane;

/**
 * This class uploads file to the Arduino.
 *
 * @version 2.6
 * @author Casper
 */
public class HEXUploader {

    // The path to the Arduino files that are used at uploading.
    private final String ARDUINOFILESFOLDERPATH = System.getProperty("user.dir");
    // The path to the Mode files.
    private String MODEFOLDERPATH;
    // The title of the OptionDialogs
    private String title;
    // The COM port that is used to transfer data through.
    private String COMPort;

    /**
     * Creates a basic HEXUploader object that cannot upload any files,
     * therefore it is useless.
     *
     */
    public HEXUploader() {
        MODEFOLDERPATH = ARDUINOFILESFOLDERPATH + "\\UploadFiles\\Modes\\";
    }

    /**
     * Creates a basic HEXUploader object with a preselected COMport so
     * uploading is possible.
     *
     */
    public HEXUploader(String COMport) {
        this.COMPort = COMport;
        MODEFOLDERPATH = ARDUINOFILESFOLDERPATH + "\\UploadFiles\\Modes\\";
    }

    /**
     * Retreives the COMPort that is used for uploading.
     *
     * @return the used COMPort.
     */
    public String getCOMPort() {
        return COMPort;
    }

    /**
     * Set the COMport value.
     *
     * @param COMPort the comport to set.
     */
    public void setCOMPort(String COMPort) {
        this.COMPort = COMPort;
    }

    /**
     * Uploads the file to the Arduino
     *
     * @param obj the Menu that the user is attempting to upload files through.
     * @param selectedMode the mode that needs te be uploaded
     */
    public void upload(Menu obj, String selectedMode) {
        title = "Mode";

        // Initialize some valuable variables
        String message;
        OutputStream out = null; // the stream that is gonna output the arguments to the command line
        Process p = null; // The connection with the process
        BufferedReader br; // We use this object later on to read chars from the Windows Command Line.


        // Ok now before we can upload files we need to specify some details of the board.
        final String cmd = "cmd.exe ";

        String pathToFiles = MODEFOLDERPATH + selectedMode + "\\" + selectedMode + ".cpp"; // The file to upload

        // The commands that need to be send to the cmd.exe
        String argument =
                ARDUINOFILESFOLDERPATH + "\\ArduinoFiles/avrdude -C" + ARDUINOFILESFOLDERPATH
                + "\\ArduinoFiles/avrdude.conf -v -v -v -v -patmega2560 -cstk500v2 -P\\\\.\\"
                + COMPort + " -b115200 -D -Uflash:w:" + pathToFiles + ".hex:i";

        /*
         * The argument -b57600 should be replaced with the correct value of the
         * corresponding board. You can find this value in the output box in the
         * Arduino IDE when uploading in verbose version.
         */

        // Some codes remaining from debugging. Please skip over.

        /*
         * sketch_may29a.cpp.hex UNO UPLOAD LINE
         * C:\arduino-1.0\hardware/tools/avr/bin/avrdude
         * -CC:\arduino-1.0\hardware/tools/avr/etc/avrdude.conf -v -v -v -v
         * -patmega328p -carduino -P\\.\COM5 -b115200 -D
         * -Uflash:w:C:\Users\Casper\AppData\Local\Temp\build8394104916657635061.tmp\sketch_may29a.cpp.hex:i
         *
         * MEGA UPLOAD LINE C:\arduino-1.0\hardware/tools/avr/bin/avrdude -CC:\arduino-1.0\hardware/tools/avr/etc/avrdude.conf -v -v -v -v -patmega2560 -cstk500v2 -P\\.\COM8 -b115200 -D -Uflash:w:C:\Users\Casper\AppData\Local\Temp\build8394104916657635061.tmp\sketch_may29a.cpp.hex:i
         */



        // The upload to Arduino via command line.
        try {
            // Create a process
            Runtime r = Runtime.getRuntime();
            p = r.exec(cmd);
            // Allocate the outputstream of the specific process and link it to 'p'
            out = p.getOutputStream(); // Define the OutputStream
            System.out.println("Stream opened to " + COMPort); // The stream is now opened


            System.out.println("Streaming: " + argument);
            // Go through all the arguments you need to upload the file
            out.write((argument + "\r\n").getBytes()); // Add a carriage return so that the command will executed and write it to the process(cmd.exe).
            out.flush();


            System.out.println("Stream closed");


            // Direct the input from the command line.
            br = new BufferedReader(new InputStreamReader(p.getErrorStream()));
            String output;

            // Read from the command line 
            while (true) {
                output = br.readLine();
                System.out.println(output);

                // If done, quit reading. Because a -1 or null at the end of stream is never given.
                if (output.equals("avrdude done.  Thank you.")) {
                    System.out.println(output);
                    break;
                }

                // Catch an error where the COMPort is already inuse.
                if (output.contains("not in sync:")) {
                    JOptionPane.showMessageDialog(obj, "Het is mislukt om de PlayPillow te veranderen, de COM poort is namelijk al reeds in gebruik."
                            + "\nWeet u zeker dat dit de poort is voor de PlayPillow?\nProbeer opnieuw.",
                            title, JOptionPane.ERROR_MESSAGE);
                    return;
                }

                // Catch an exception that might occur when the user replaces/removes files. 
                if (output.contains("No such file or directory")) {
                    JOptionPane.showMessageDialog(obj, "Het is mislukt om de PlayPillow te veranderen. De reden hiervoor is dat de bestanden verplaatst zijn in dit programma."
                            + "\nPlaats de bestanden/mappen terug en probeer opnieuw.",
                            title, JOptionPane.ERROR_MESSAGE);
                    return;
                }
            }
            System.out.println("Reached end");
        } catch (IOException e) {
            System.out.println(e);
        } finally {

            // Get some stuff straight; the process needs to be destroyed and the output must be closed for other processes.
            try {
                // Destroy the process.
                p.destroy();
                // Close the output.
                out.close();
            } catch (IOException exc) {
                exc.printStackTrace();
            }
        }

        // Display the final things to the user.
        message = "Als het goed is werkt de PlayPillow nu naar behoren.\n"
                + "Als dit niet het geval is probeer dan opnieuw de PlayPillow aan te passen.";
        javax.swing.JOptionPane.showMessageDialog(obj, message, title, JOptionPane.INFORMATION_MESSAGE);
    }
}
