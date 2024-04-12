This Repository contains the code for both of team Ra's Flight Arduinos.

## To Start
Clone this repository to your computer, it does not need to be stored in the Arduino folder, but it will be easier to deploy code from Arduino
IDE.

There are three main parts of this repository: Test Code, Primary Flight Code, and Secondary Flight Code. Primary and Secondary Flighrt Code are housed in Flight_Code, and all code intended for troubleshooting hardware is in Test_Code. Generally, it is preferable to use code from the main branch, as other branches could have experemental and faulty code. In some cases faulty code could damage hardware. 

To deploy code to an Arduino open the cloned repository stored on your computer. Navigate to the file you would like to deploy. Note each .ino file is necesarilly stored in a folder of it's own name. Deleating these folders, or re-naming them will cause issues. Open the .ino file, this should automatically open the Arduino IDE if you have it installed. If it does not open automatically, use OpenWith => Arduino IDE. This should open any dependant Files as well. Conect the Arduino to your computer, select your board and port and sellect the arrow. Make sure that no error messages appear, the code should fully upload in a matter of seconds.

## Reminders
-Only use the Main branch for Mechanical testing. Other Branches could have errors, and using them could damage hardware. /n
-Upload code using the Arduino IDE. While it is possible to use other programs like VS Code, it is not necesary to this project and will cause problems.
-In the Secondary Flight Code there is a timer which prevents the propellers from activating before the module has been launched. This may need to be changed if the control loop is being tested.
