/* countDownSerial example
 *
 * counts down the watch and prints the result to the Serial Monitor.
 * Results can be reviewed using the Serial monitor (Tools > Serial monitor menu).
 * For accurate timekeeping, consider reading about using timers and interrupts.
 * 
 * This example code is in the public domain.
 * 
 * Created apr 21 2019
 * By Sebastian R Alterman
 */
//include the library code
#include <Watch.h>
/* We will be using the watch as a global variable so that we 
 * can access it both within setup and loop.
 */
Watch myWatch; //by default it starts in 00:00

void setup() {
  Serial.begin(9600); // The serial port is used as the main output
  /*The Watch has two parts in this examṕle, minutes and seconds. 
  *   - The MSD or Most Significant Digits would be the minutes
  *   - The LSD or Least significant digits would be the seconds
  */
  myWatch.setWatch(0,1); //the shortest unit goes first! sothis would represent 01:00
}
// the loop routine runs over and over again forever:
void loop() {
  //print the current watch one part at the time
  Serial.print(myWatch.getMSD()); 
  Serial.print(":");
  Serial.print(myWatch.getLSD());
  Serial.println(); //new line
  myWatch.countDown(); //perfom the count
  delay(1000); // wait for one second
}
