#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct Q
{
 int data[MAX];
 int R,F;
}Q;

typedef struct node
{
 struct node *next;
 int vertex;
}node;

void enqueue(Q *,int);
int empty(Q *);
int full(Q *);
void BFS(int);
void readgraph();      //create an adjecency list
void insert(int vi,int vj);     //insert an edge (vi,vj)in adj.list
int dequeue(Q *P);
int visited[MAX];
node *G[20];          //heads of the linked list
int n;                 // no of nodes

void main()
{
 int i,op;

 do
   { printf("\n\n1)Create\n2)BFS\n3)Quit");
     printf("\nEnter Your Choice: ");
     scanf("%d",&op);
     switch(op)
      { case 1: readgraph();break;
        case 2: printf("\nStarting Node No. : ");
         scanf("%d",&i);
         BFS(i);break;
        
       }
    }while(op!=3);
}


void BFS(int v)
{
 int w,i,visited[MAX];
 Q q;

 node *p;
 q.R=q.F=-1;              //initialise
 for(i=0;i<n;i++)
  visited[i]=0;
 enqueue(&q,v);
 printf("\nVisit\t%d",v);
 visited[v]=1;
 while(!empty(&q))
 {
  v=dequeue(&q);
  //insert all unvisited,adjacent vertices of v into queue
  for(p=G[v];p!=NULL;p=p->next)
  {
   w=p->vertex;
   if(visited[w]==0)
   {
    enqueue(&q,w);
    visited[w]=1;
    printf("\nvisit\t%d",w);
   }
  }
 }
}




int empty(Q *P)
{
 if(P->R==-1)
  return(1);
 return(0);
}

int full(Q *P)
{
 if(P->R==MAX-1)
  return(1);
 return(0);
}

void enqueue(Q *P,int x)
{
 if(P->R==-1)
 {
  P->R=P->F=0;
  P->data[P->R]=x;
 }
 else
 {
  P->R=P->R+1;
  P->data[P->R]=x;
 }
}

int dequeue(Q *P)
{
 int x;
 x=P->data[P->F];
 if(P->R==P->F)
 {
  P->R=-1;
  P->F=-1;
 }
 else
  P->F=P->F+1;
 return(x);
}

void readgraph()
{  int i,vi,vj,no_of_edges;
 printf("\nEnter no. of vertices :");
 scanf("%d",&n);
 //initialise G[] with NULL
 for(i=0;i<n;i++)
  G[i]=NULL;
 //read edges and insert them in G[]
 printf("\nEnter no of edges :");
 scanf("%d",&no_of_edges);
 for(i=0;i<no_of_edges;i++)
 {
  printf("\nEnter an edge (u,v)  :");
  scanf("%d%d",&vi,&vj);
  insert(vi,vj);
  insert(vj,vi);
 }
}

void insert(int vi,int vj)
{
 node *p,*q;
 //acquire memory for the new node
 q=(node *)malloc(sizeof(node));
 q->vertex=vj;
 q->next=NULL;
 //insert the node in the linked list for the vertex no. vi
 if(G[vi]==NULL)
  G[vi]=q;
 else
 {
  // go to the end of linked list
  p=G[vi];
  while(p->next!=NULL)
   p=p->next;
  p->next=q;
 }
}
     #include<stdio.h>
   
    int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;
    void bfs(int v) {
    	for (i=1;i<=n;i++)
    	  if(a[v][i] && !visited[i])
    	   q[++r]=i;
    	if(f<=r) {
    		visited[q[f]]=1;
    		bfs(q[f++]);
    	}
    }
    void main() {
    	int v;
    	
    	printf("\n Enter the number of vertices:");
    	scanf("%d",&n);
    	for (i=1;i<=n;i++) {
    		q[i]=0;
    		visited[i]=0;
    	}
    	printf("\n Enter graph data in matrix form:\n");
    	for (i=1;i<=n;i++)
    	  for (j=1;j<=n;j++)
    	   scanf("%d",&a[i][j]);
    	printf("\n Enter the starting vertex:");
    	scanf("%d",&v);
    	bfs(v);
    	printf("\n The node which are reachable are:\n");
    	for (i=1;i<=n;i++)
    	  if(visited[i])
    	   printf("%d\t",i); else
    	   printf("\n Bfs is not possible");
    	
    }
