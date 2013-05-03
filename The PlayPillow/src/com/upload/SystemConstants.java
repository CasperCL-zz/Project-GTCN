package com.upload;

/**
 * This interface provides enough data from the system.
 *
 * @version 2.5
 * @author Casper
 */
public interface SystemConstants {

    // Gets the Operating System's name
    String OS = System.getProperty("os.name");
    // Checks if the current OS in use is in fact Windows
    boolean isWindows = System.getProperty("os.name").contains("Windows");
    // The Java Library Path for UNIX-based systems
    String javaLibPathUnix = System.getProperty("java.library.path").split(":")[0];
    // The Java Library Path for Windows NT systems
    String javaLibPathWindows = System.getProperty("java.library.path").split(";")[0];
}
