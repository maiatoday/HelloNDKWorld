HelloNDKWorld
=============

Hello world using NDK in gradle and android studio

This is a skeleton app that has a HelloWorld activity and a integrates the NDK. The jni folder is 
in the HelloNDKWorld folder. To do an ndk build first set the path to NDK installation by creating a file gradle.properties in the HelloNDKWorldProject directory. It should contain a line that looks like this:
   ndkDir=/yourInstallationDirectory/android-ndk-r9
There is a gradle task to run the build but a normal build will also trigger an ndk-build. The resulting .o files are zipped up in a jar in the build/native-libs folder.
If you only want to do the ndk build and package the libs do the following command:
  ./gradlew ndk
  
  Since creating this project, some new NDK support has been added to gradle android plugin. So this project is no longer that necesssary. Look here to see how to do this. https://software.intel.com/en-us/videos/using-the-ndk-with-android-studio
