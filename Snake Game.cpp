#include<bits/stdc++.h>
#include <conio.h>
#include <fstream>

using namespace std;
#define size 30
struct snake{
	int x;
	int y;
	char val;
	struct snake *next;
};
struct food{
	int x;
	int y;
	char val;
};

 
 
 
snake* generatesnake(struct snake *head,int no, int & score){	

fstream file;
   file.open("C:\\Users\\HP LAPTOP\\OneDrive\\Documents\\snake.txt", ios :: in);
	head=NULL; int i,x=size/2,y=size/2;
	
	if(no==1)
{
	for(i=0;i<3;i++){
		struct snake *n;
		n=new snake;                            

		n->next=NULL;
		if(head==NULL)
		{
			n->x =x;
			n->y =y--;
		n->val='A';
	head=n;
		}
		else{
			n->x=x;
			n->y=y--;
			n->val='o';
			struct snake *t;
		for(t=head;t->next!=NULL;t=t->next){}
		t->next=n;
		}
		}
		}
	else
	{
		
		char c,str[100]; int i=0;
		c=file.get();
		score=(int)c;
			while (file.get(c) != '\0'){
				str[i++]=c;
			}
			str[i]='\0'; i=0;
	 while(str[i]!='\0'){
		  	struct snake *n;
		n=new snake;                            

		n->next=NULL;
		if(head==NULL)
		{
			n->val=str[i++];
			n->x = (int)str[i++];
			n->y =(int)str[i++];
		
	head=n;
		}
		else{
			n->val=str[i++];
			n->x = (int)str[i++];
			n->y =(int)str[i++];
			struct snake *t;
		for(t=head;t->next!=NULL;t=t->next){}
		t->next=n;
		}
    }
	}
	file.close();
		return head;
	}
food* generatefood(struct snake *head,struct food *f){
	f=new food; int fl=1;
	while(fl!=0){
		fl=0;
	f->x=rand()%size;
f->y=rand()%size;
		f->val='+';
	for(struct snake * t=head;t!=NULL;t=t->next)
	{
		if(f->x==t->x && f->y==t->y) fl=1;
	}
}
	return f;
}
int gotfood(struct snake *head,struct food *f,int x,int y){
		struct snake *n,*t;
		n=new snake;
		n->next=NULL;
		n->val='o';
		
		for(t=head;t->next!=NULL;t=t->next){}
		t->next=n;
		n->x=x;
		n->y=y;
		return 1;
}
void savegame(struct snake* head,struct food *f,char s){
	fstream file; char str[100]; int i=0;
   file.open("C:\\Users\\HP LAPTOP\\OneDrive\\Documents\\snake.txt", ios :: out);
  	file<<s;
	for(struct snake* t=head;t!=NULL;t=t->next)
		{
			str[i++]=t->val;
			str[i++]=t->x;
			str[i++]=t->y;
		}
		str[i]='\0';
	for(int j=0;j<=i;j++)
			file<<str[j];
		
			file.close();
}
void clearboard(char a[][size+1]){
	for(int i=0;i< size+1;i++)
		for(int j=0;j< size+1;j++)
			a[i][j]=' ';
}
void movetoboard(char a[][size+1],struct snake *head,struct food *f){
	for(int i=0;i<size+1;i++)
	{a[0][i]='#';
	a[i][0]='#';
	a[size][i]='#';
	a[i][size]='#';
}
	for(struct snake *t=head;t!=NULL;t=t->next)
	 	a[t->x][t->y]=t->val;
	 a[f->x][f->y]=f->val;
}
int correctdir(char c,char prev){

if(prev=='a'&&c=='d' ||prev=='A'&&c=='D'||prev=='W'&&c=='S'||prev=='w'&&c=='s'||
prev=='d'&&c=='a'||prev=='D'&&c=='A'||prev=='S'&&c=='W'||prev=='s'&&c=='w'
) return 0;
return 1;

}
int checkheadtou(struct snake *head,int g){
	struct snake *t;
	for(t=head->next;t!=NULL;t=t->next)
		if(head->x==t->x && head->y==t->y) g=1;
	return g;
}
int movesnake(struct snake *head,struct food *f,char c,char &prev){
		int x,y,px,py,fl=0;
			struct snake *t=head;
				prev=c;
	if(c=='w')
	{
	
			for(t=head;t!=NULL;t=t->next){
				if(t==head){
					px=x=t->x; py=y=t->y; t->x=x-1;
					if(t->x==0) t->x=size-1;
					if(t->x==f->x && t->y==f->y) fl=1;
				}
				else{
					px=x;py=y;
					x=t->x; y=t->y;	t->x=px; t->y=py;
					
					if(t->x==0) t->x=size-1;
			}
		}
	}
	else if(c=='a')
	{			
		for(t=head;t!=NULL;t=t->next){
				if(t==head){
					px=x=t->x; py=y=t->y; t->y=y-1;
					if(t->y==0) t->y=size-1;	if(t->x==f->x && t->y==f->y) fl=1;
				}
				else{
						px=x;py=y;
					x=t->x; y=t->y;	t->x=px; t->y=py;
				if(t->y==0) t->y=size-1;
				}
			}
	}
	else if(c=='s')
	{
			for(t=head;t!=NULL;t=t->next){
				if(t==head){
					px=x=t->x; py=y=t->y; t->x=x+1;
					if(t->x==size) t->x=1;	if(t->x==f->x && t->y==f->y) fl=1;
				}
				else{
					px=x;py=y;
					x=t->x; y=t->y;	t->x=px; t->y=py;
					if(t->x==size) t->x=1;
				}
			}
	}
	else if(c=='d')
	{
			for(t=head;t!=NULL;t=t->next){
				if(t==head){
					px=x=t->x; py=y=t->y; t->y=y+1;
					if(t->y==size) t->y=1; 	if(t->x==f->x && t->y==f->y) fl=1;
				}
				else{
						px=x;py=y;
					x=t->x; y=t->y;	t->x=px; t->y=py;
				}
			}
	}
	else
		cout<<"INVALID INPUT try with different input or input n to exit game";
		if(fl==1) return gotfood(head,f,x,y);
		else return 0;
	}
void print(char a[][size+1]){
	int i,j;
	for(i=0;i< size+1;i++)
	{
		for(j=0;j< size+1;j++)
			cout<<a[i][j];
		cout<<endl;
	}
}
void welcomescreen(){
	cout<<"-------------------------------------------"<<endl;
	cout<<"|    ____  ___   __ ____   _    __  ____   |"<<endl;
	cout<<"|   [  _*||   \\ | || __ | | |  / / | ___|  |"<<endl;
	cout<<"|   | {   | |\\ \\| |||__|| | |_/ /  |{__    |"<<endl;
	cout<<"|    \\ \\  | | \\ | |||  || | | \\ \\  |{___   |"<<endl;
	cout<<"|   __}_} |_|  |__|||  || |_|  \\_| |____|  |"<<endl;
	cout<<"|                                      GAME|"<<endl;
	cout<<"|  ->Enter 1 for a new game                |"<<endl;
	cout<<"|  ->Enter 2 to  resume game	           |"<<endl;	
	cout<<"-------------------------------------------|"<<endl;	
}
int main(){
	system("mode con: cols=100 lines=35");
	char a[size+1][size+1];
	int score=0; float speed=100.00;
	struct snake *head; struct food *f;
	welcomescreen();
	int no;
	cin>>no;
	head=generatesnake(head,no,score);
	f=generatefood(head,f);
	char ch='d',prev='l';
	int g=0;
	while(ch!='n' )
	{
		_sleep(speed);
	system("cls");
	clearboard(a);
	 if(kbhit())
	    ch=getch();                                                                 
	 
	if(correctdir(ch,prev))
	 {
	 int j=movesnake(head,f,ch,prev);
		if(j==1) {
			f=generatefood(head,f);
			score++;
			savegame(head,f,(char)score);
		}
	}      
	  
	
	if(checkheadtou(head,g))
		if(correctdir(ch,prev))
			break;
	movetoboard(a,head,f);
	print(a);
	cout<<"\t\t\tScore:"<<score<<endl;
	}
	cout<<"-------GAME OVER---------- \n Your Score is:"<<score<<endl;

	return 0;
}                 
