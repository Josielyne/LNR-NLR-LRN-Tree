#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
using namespace std;
class Tree//class to make BST
{
	public:
		//declare variables needed for tree
		int data;//data for tree
		Tree *left;//left side of tree
		Tree *right;//right side of tree
		
		Tree()//constructor
		{
			//initialize variables
			data = 0;
			left = nullptr;
			right = nullptr;
			
			
		}
		Tree* insertNode(Tree *node, int data)//insert node in tree
		{
			if (node == nullptr)//if tree or subtree is empty create a root
			{
				node = new Tree();
				node->data = data;
				node->left = nullptr;
				node->right = nullptr;
				

			}
			else if (data < node->data)//if value is less than root value
			{
				//recursive call
				node->left = insertNode(node->left, data);//create node on left
			}
			else if (data > node->data)//if value is greater than root value
			{
				//recursive call
				node->right = insertNode(node->right, data);//create node on right
			}

			return node;//return node pointer
			}
		Tree *minValue(Tree *node)//find node with lowest value in tree or subtree
		{
			Tree *current = node;
			while (current && current->left != nullptr)//find leftmost node
			{
				current = current->left;
			}
			return current;//return node with min value
		}
		Tree *deleteNode(Tree *node, int data)//delete node in tree
		{

			if (node == nullptr)//if tree is empty
			{
				return node;
			}

			else if (data < node->data) //if value to be deleted is less than root's value
			{
				node->left = deleteNode(node->left, data);//go to left and delete
			}
			else if (data > node->data)//if value to be deleted is greater than root's value
			{
				node->right = deleteNode(node->right, data);//go to right and delete
			}
			else//if value to be deleted is the same as root value
			{
				//delete noode with no child or one child
				if (node->left == nullptr)//left side
				{
					Tree *temp = node->right;//temp node created to get child
					delete node;//parent is deleted
					return temp;//child is returned
				}
				else if (node->right == nullptr)//right side
				{
					Tree *temp = node->left;//temp node created to get child
					delete node;//parent is deleted
					return temp;//child is returned
				}
				//delete node with two children
				Tree *temp = minValue(node->right);//get smallest node in right subtree
				node->data = temp->data;//child data copied to parent data
				node->right = deleteNode(node->right, temp->data);//delete parent

			}
			return node;//return node pointer

		}
		void inOrder(Tree *root)//LNR traversal
		{

			if (root != nullptr)//as long as tree isn't empty
			{
				inOrder(root->left);//traverse left side
				cout << root->data << " ";//print value of current node
				inOrder(root->right);//traverse right side
				
			}

		}
		void preOrder(Tree *root)//NLR traversal
		{
			if (root != nullptr)//as long as tree isn't empty
			{
				cout << root->data << " ";//print value of current node
				preOrder(root->left);//traverse left side
				preOrder(root->right);//traverse right side
			
			}
		}
		void postOrder(Tree *root)//LRN traversal
		{
			if (root != nullptr)//as long as tree isn't empty
			{
				postOrder(root->left);//traverse left side
				postOrder(root->right);//traverse right side
				cout << root->data << " ";//print value of current node
			
			}


	    }
};
void gotoxy(int column, int line)//gotoxy for coordinate movement
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}
void DisplayMenu()//Displays Menu of Options
{
	//builds menu with symbols and coordiante movement
	gotoxy(38, 0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);//makes menu rainbow colored
	cout << "+=================================+";
	gotoxy(38, 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 542);
	cout << "+";
	gotoxy(54, 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "Menu";
	gotoxy(38, 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 542);
	cout << "+";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << " 1=Insert   2=Delete   3=Exit" << endl;
	gotoxy(38, 3);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 542);
	cout << "+";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << " 4=LNR      5=NLR      6=LRN" << endl;
	gotoxy(38, 4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "+=================================+";
	gotoxy(72, 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 542);
	cout << "+";
	gotoxy(72, 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 542);
	cout << "+";
	gotoxy(72, 3);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 542);
	cout << "+";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoxy(29, 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "Choose ";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
cout << "The ";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
cout << "Action ";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
cout << "You ";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
cout << "Want ";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
cout << "To ";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
cout << "Perform ";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
cout << "From ";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
cout << "The ";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
cout << "Menu ";
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
}

void DisplayTree(Tree *r, int xpos, int ypos, int width)//Displays BST as diagram
{
	
	if (r == nullptr)//if tree is empty
	{
		return;
	}
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);//color that makes tree rainbow
		gotoxy(xpos, ypos + 1);
		cout << "|";//part of branch for tree
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		gotoxy(xpos, ypos + 2);
		cout << "|";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		gotoxy(xpos, ypos + 3);
		cout << "|";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		gotoxy(xpos, ypos);
		if (r->data < 10)//if displaying value with single digits
		{
			//loop to display part of branch on left
			for (int i = 0; i <= (width / 2) - 2;i++)//use width to keep track of how many = to use
			{
				//add extra = sign
				cout << "=";

			}
		}
		else
		{
			//if displaying value with double digits
			//loop to display part of branch on left
			for (int i = 0; i < (width / 2) - 2;i++)//use width to keep trach of how many = to use
			{
				cout << "="; //display = sign

			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "|" << r->data << "|";//prints node value
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		//loop to display part of branch on right
		for (int i = 0; i < (width/2)-2;i++)//use width to keep track of how many = to use
		{
			cout << "="; //display = sign
		
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		gotoxy(xpos+(width/2)*2, ypos + 1);//use width to display branch in correct coordinates to make it look centered
		//part of branch for tree
		cout << "|";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		gotoxy(xpos + (width / 2)*2, ypos + 2);
		cout << "|";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		gotoxy(xpos + (width / 2)*2, ypos + 3);
		cout << "|";
		width = width / 2;//change width
	
		//recursive call to display right side
		DisplayTree(r->right, xpos + (width*2)-(width/3)-1, ypos + 4, width);
		//recursive call to display left side
		DisplayTree(r->left, xpos - width/2, ypos + 4, width);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

	
}
Tree* UserChoice(Tree *root)//function that processes user choice
{
	//user chooses what they want to do from the displayed menu
	int choice;
	int val;
	cout << endl;
	cin >> choice;
	
	switch (choice)//switch to process choices
	{
	case 1://if user wants to insert
		system("cls");//clear screen
		DisplayMenu();//redisplay menu
		gotoxy(0, 6);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);//change color according to choice
		cout << "Enter The Value You Want To Add To The Tree" << endl;//asks user to enter value they want to add to tree
		cin >> val;
		cout << "Next Choice" << endl;//asks user to choose another choice from menu
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		if (root == nullptr)//if there's no root, create root
		{
			root = root->insertNode(root, val);
			
		}
		else//create node and insert node to tree
		{
			root->insertNode(root, val);
		}

		gotoxy(0, 11);
		DisplayTree(root, 40, 11, 30);//display entire tree
	
		gotoxy(0, 8);
		return root;//return root of tree
	
		break;
	case 2://if user want to delete
		system("cls");//clear screen
		DisplayMenu();//redisplay menu
		gotoxy(0, 6);	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << "Enter The Value You Want To Delete From The Tree" << endl;//asks user to enter value they want to delete from tree
		cin >> val;
		cout << "Next Choice" << endl;//asks user to choose another choice from menu
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		root->deleteNode(root,val);//deletes node containing chosen value
		
		gotoxy(0, 11);
		DisplayTree(root, 40, 11, 30);//displays entire tree
		
		gotoxy(0, 8);
		return root;//returns root of tree
	
		break;
	case 3://if user wants to exit the program
		root = nullptr;//empties tree
		return root;//returns root of tree
		break;
	case 4://if user wants to display values in LNR
		system("cls");//clear screen
		DisplayMenu();//redisplay menu
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);//changes color according to choice
		gotoxy(0, 6);
		cout << "In Order Traversal:" << endl;//displays values in LNR
		root->inOrder(root);//calls LNR function
		cout << endl <<"Next Choice" << endl;//asks user to choose another choice from menu
		gotoxy(0, 11);
		DisplayTree(root, 40, 11, 30);//displays entire tree
	
		gotoxy(0, 8);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		return root;//returns root of tree
		
		break;
	case 5://if user wants to display values in NLR
		system("cls");//clear screen
		DisplayMenu();//redisplay menu
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		gotoxy(0, 6);
		cout << "Pre Order Traversal:" << endl;//displays values in NLR
		root->preOrder(root);//calls NLR function
		cout << endl << "Next Choice" << endl;//asks user to choose another choice from menu
		gotoxy(0, 11);
		DisplayTree(root, 40, 11, 30);//displays entire tree
		gotoxy(0, 8);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		return root;//returns root of tree
		
		break;
	case 6://if user wants to display values in LRN
		system("cls");//clear screen
		
		DisplayMenu();//redisplay menu
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		gotoxy(0, 6);
		cout << "Post Order Traversal:" << endl;//displays values in LRN
		root->postOrder(root);//calls LRN function
		cout << endl << "Next Choice" << endl;//asks user to choose another choice from menu
		gotoxy(0, 11);
		DisplayTree(root, 40, 11, 30);//displays entire tree
	
		gotoxy(0, 8);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		return root;//returns root of tree
	
		break;
	default://default for case
		break;

	}
	
}
void endProgram()//displays thank you at end of program
{
	gotoxy(50, 15);//centers message
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);//makes message rainbow
	cout << "Th";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "an";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "k ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "Yo";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << "u!" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
int main()//dirver of class
{
	system("color 0A");//changes color
	DisplayMenu();//displays menu at top
	gotoxy(0, 6);
	Tree* root = nullptr;//initiates tree
	do//do while to keep carrying out functions offered by menu
	{
	
	root = UserChoice(root);//change tree according to choice from menu
	
	

	} while (root!=nullptr);//if tree is empty, exit the loop


	endProgram();//calls end function
	gotoxy(0, 29);

	return 0;
}
