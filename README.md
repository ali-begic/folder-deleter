# Folder Deleter

The **Folder Deleter** application simplifies the process of removing folders by automating their deletion across multiple directories. Designed to handle situations where a folder with the same name exists in various locations, including nested subdirectories and hidden folders, this tool allows users to specify a parent directory and efficiently delete all instances of the specified folder. With options to include or exclude hidden folders, this application ensures thorough and flexible folder management, saving time and effort compared to manual deletion.

![folder-deleter-capture](https://github.com/user-attachments/assets/13ac68f7-4f5c-43f5-b555-1fbe77df4462)

## Features of the Folder Deleter Qt Application

### Cross-Platform Compatibility
- Compatible with various operating systems, ensuring that users can delete folders regardless of their platform.

### User-Friendly Interface
- A simple and intuitive interface designed with the Qt framework, making it easy to navigate and use.

### Multiple Folder Deletion
- **Select Multiple Folders**: Allows users to select and delete multiple folders simultaneously, either through a file dialog or by specifying folder paths manually.

### Recursive Deletion
- **Delete Subfolders**: Option to delete folders and their contents recursively, including all subfolders within the selected directory.

### Hidden Folder Deletion
- **Delete Hidden Folders**: Provides the option to include hidden folders in the deletion process, giving users complete control over what gets deleted.

### Confirmation and Error Handling
- **Confirmation Prompts**: Asks for confirmation before deleting folders, preventing accidental deletions.
- **Error Handling**: Properly handles errors when folders do not exist or cannot be deleted, ensuring smooth operation.

### Customizable Deletion Options
- **Ask Before Each Deletion**: Allows users to enable or disable prompts for each folder being deleted.
- **Selective Deletion**: Users can choose to delete only visible folders or include hidden ones as well.

### Real-Time Feedback
- **Success/Failure Messages**: Displays messages to inform users of successful deletions or any issues encountered during the process.

### Efficient Performance
- **Fast Deletion Process**: Optimized for quickly deleting multiple folders, minimizing wait times and enhancing user productivity.

### Error Message Display
- **Empty Input Validation**: Displays an error message if no folder is specified for deletion, ensuring users provide necessary input before proceeding.

These features make the **Folder Deleter** a reliable tool for efficiently managing and deleting folders, giving users full control over the deletion process while ensuring safety and convenience.

## Building the Qt Application from Source

To build and run the **Folder Deleter** application from source, it would be best solution to open the application in [Qt Creator](https://www.qt.io/), then compile it to your liking. But if you want to do it manually, here are the steps you need to follow: 

1. **Clone the Repository:**
   - Ensure you have Git installed on your system.
   - Open your terminal or command prompt and navigate to the directory where you want to clone the repository.
   - Run the following command:
     ```
     git clone https://github.com/ali-begic/folder-deleter
     ```
   - Navigate into the cloned directory:
     ```
     cd folder-deleter
     ```

2. **Install Qt Dependencies:**
   - Ensure you have the necessary Qt libraries, compilers, and build tools installed. Refer to the official Qt documentation for platform-specific instructions:
     - [Qt Documentation for Windows](https://doc.qt.io/qt-6/windows-deployment.html)
     - [Qt Documentation for macOS](https://doc.qt.io/qt-6/macos-deployment.html)
     - [Qt Documentation for Linux](https://doc.qt.io/qt-6/linux-deployment.html)

3. **Configure and Build:**
   - Create a build directory and navigate into it:
     ```
     mkdir build
     cd build
     ```
   - Run `qmake` to generate the Makefile from the `.pro` file:
     ```
     qmake ../src/folderDeleter.pro
     ```
   - Compile the application:
      - On Windows with MSVC:
        ```
        nmake
        ```
      - On Windows with MinGW:
        ```
        mingw32-make
        ```
      - On macOS and Linux:
        ```
        make
        ```

4. **Run Your Application:**
   - After a successful build, the executable will be located in the build directory.
   - Run the application:
     ```
     ./folderDeleter
     ```
   - On Windows, you can find the executable in the release or debug directory depending on your build configuration.

## Using `windeployqt` for Windows Deployment

To deploy the **Folder Deleter** application on Windows, you can use the `windeployqt` tool. This tool automatically copies the necessary Qt runtime files (DLLs, plugins, etc.) to your application's deployment folder, making it easier to distribute the application.

### Steps to Use `windeployqt`:

1. **Build Your Application:**
   - Ensure that your application is fully built using the steps above.

2. **Open the Correct Command Prompt:**
   - Open the "Developer Command Prompt for VS 2022" or the "Qt MinGW" command prompt, depending on the compiler you used.

3. **Navigate to the Build Directory:**
   - Use the command prompt to navigate to the directory where your application’s executable is located:
     ```bash
     cd ../folder-deleter/build/release
     ```

4. **Run `windeployqt`:**
   - Run the following command to deploy your application:
     ```bash
     windeployqt folderDeleter.exe
     ```

5. **Test the Deployed Application:**
   - After running `windeployqt`, test the application by running the executable in its deployment directory to ensure all dependencies are correctly deployed.

6. **Distribute the Application:**
   - You can now package the deployed files (including the executable and all copied DLLs and plugins) into a ZIP file, installer, or other distribution formats for distribution.

## Contributing

Contributions are welcome! If you find a bug, have a feature request, or want to improve the code, feel free to open an issue or submit a pull request.

## License

This project is licensed under the Apache-2.0 license - see the [LICENSE](LICENSE) file for details.

## Additional Notes

- Ensure that you have the correct version of Qt and associated build tools for your platform.
- If you encounter issues, check the Qt and compiler documentation or seek assistance on community forums.
- If the application still does not work properly, try running it as an administrator.

Thank you for your interest in the **Folder Deleter** application!
