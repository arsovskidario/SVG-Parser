/*For the user :
 * 1.for opening a file you need to use the exact same path the file is located on your machine
 * examples : C:\Dev\shapes.txt  C:\Users\Name\Desktop\shapes.svg 
 * so the full command will be open C:\Dev\shapes.txt
 * 2. for saving the file no path is required ,but
 * for using saveAs you need to specify a path as the one shown above.
 * example for saveAs : saveAs C:\Users\Name\Desktop\shapes.svg
 * 3.These command don't need any parameters :
 * save,print and close 
 * 4.for creating a shape with the create command you need to specify the shape 
 * and all of the required attributes. Examples for create command listed below:
 * create rectangle x y width height fill stroke
 * create circle x y radius fill stroke
 * create ellipse x y rx ry fill stroke 
 * 5.the erase command requires only an index
 * example erase 2 
 * 6.The translate command requires you to enter the keywords horizontal and vertical
 * examples translate horizontal=5 //translate the x coord of all figures by 5
 *          translate circle horizontal=5 vertical=2
 * 7. The within command requires you to enter the shape and it's parameters 
 * examples:
 * within circle 0 2 5 ->x,y,radius
 * within rectangle 5 5 25 30->x,y,width,height
 */
#include<iostream>
#include <string>
#include "UserInterface.h"

void help();

int main()
{
	help();
	UserInterface engine;
	engine.start();
}
void help()
{
	std::cout << "Please enter a command in order to start ! \n";
	std::cout << "If you are not familiar with the commands the instructions are listed above in the comments. \n";
}