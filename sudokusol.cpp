#include<bits/stdc++.h>
using namespace std;
void print_solution(char** sudoku,int n)
{
  cout<<endl;
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)cout<<sudoku[i][j]<<" ";
    cout<<endl;
  }
}
bool row(char** sudoku,int r,int num,int n)
{
  int j;
  for(j=0;j<n;j++){if((sudoku[r][j]-'0')==num)return false;}
  return true;
}
bool col(char** sudoku,int c,int num,int n)
{
  int i;
  for(i=0;i<n;i++){if((sudoku[i][c]-'0')==num)return false;}
  return true;
}
bool grid(char** sudoku,int r,int c,int num,int n)
{
  int i,j;
  for(i=(r*3);i<(r*3)+3;i++)
  {
    for(j=(c*3);j<(c*3)+3;j++){if((sudoku[i][j]-'0')==num)return false;}
  }
  return true;
}
bool issafe(char** sudoku,int r,int c,int num,int n)
{
  return (row(sudoku,r,num,n)&&col(sudoku,c,num,n)&&grid(sudoku,r/3,c/3,num,n));
}
void solver(char** sudoku,int r,int c,int n)
{
  if(c==n){r++;c=0;}
  if(r==n){print_solution(sudoku,n);return;}
  if(sudoku[r][c]!='.'){solver(sudoku,r,c+1,n);return;}
  for(int i=1;i<10;i++)
  {
    if(!issafe(sudoku,r,c,i,n))continue;
    sudoku[r][c]=((char)(48+i));
    solver(sudoku,r,c+1,n);
    sudoku[r][c]='.';
  }
}
int main(void)
{
  int n,i,j;
  cout<<"Enter the size of each row/column in the sudoku puzzle"<<endl;
  cin>>n;
  cout<<endl;
  cout<<"Enter the elements of the sudoku puzzle, for an empty cell, enter '.', for a cell containing a number, enter the number"<<endl<<endl;
  char** sudoku=new char*[n];
  for(i=0;i<n;i++)
  {
    sudoku[i]=new char[n];
    for(j=0;j<n;j++)cin>>sudoku[i][j];
  }
  solver(sudoku,0,0,n);
  return 0;
}
