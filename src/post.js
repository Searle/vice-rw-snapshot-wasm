Module.finish_main= function() {
    console.log("XXXXXX1");
    
    // Poll until after_main has been called
    // Module.after_main();

    console.log("XXXXXX2");
    
    // Read the file from the virtual file system after the runtime is initialized
    const content = Module.FS_readFile("/test1.vsf");
    console.log("File content:", content);
};
