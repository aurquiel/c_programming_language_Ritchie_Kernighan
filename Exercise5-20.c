/*Exercise 5-20. Expand dcl to handle declarations with function 
argument types, qualifiers like const, and so on.*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
enum { NAME, PARENS, BRACKETS};
enum { NO, YES};
void dcl(void);
void dirdcl(void);
void errmsg(char *);
void dclspec(void);
int typespec(void);
int typeequal(void);
int compare(char **, char**);
void parmdcl(void);

int gettoken(void);
extern int tokentype;
extern char token[];
extern char name[];
extern char datatype[];
extern char  out[];
extern int prevtoken;


//dcl:parse a declarator
void dcl(void)
{
 int ns;
 for(ns = 0; gettoken() == '*';)
  ns++;
 dirdcl();
 while(ns --> 0)
  strcat(out, "pointer to");
}


//dirdcl: parse a direct declaration
void dirdcl(void)
{
 int type;
 void parmdcl(void);
 if(tokentype == '('){
  dcl();
  if(tokentype != ')')
   errmsg("error:missimg)\n");
 }
 else if(tokentype == NAME){
  if(name[0] == '\0')
   strcpy(name,token);
 }else
  prevtoken = YES;
 while((type = gettoken()) == PARENS || type == BRACKETS || type == '(')
  if(type == PARENS)
   strcat(out, "function returning");
  else if(type == '('){
   strcat(out, "function expecting");
   parmdcl();
   strcat(out, "and returning");
  } else{


   strcat(out, "array");
   strcat(out, token);
   strcat(out, "of");
  }
}

//errmsg: prints the error message
void errmsg(char *msg)
{
 printf("%s\n",msg);
 prevtoken = YES;
}


//get token:return next token
int gettoken(void)
{
 int c, getch(void);
 void ungetch(int);
 char *p = token;
 if(prevtoken == YES) {
  prevtoken = NO;
  return tokentype;
  while((c = getch()) == ' ' || c == '\t')
   ;
  if(c == '('){
   if ((c = getch()) == ')'){
    strcpy(token,"()");
    return tokentype = PARENS;
   }
   else{
    ungetch(c);
    return tokentype = '(';
   }
  }
  else if(c == '['){
   for(*p++ = c; (*p++ = getch()) != ']';)
    ;
   *p = '\0';
   return tokentype = BRACKETS;
  }
  else if (isalpha(c)) {
   for(*p++ = c; isalnum(c = getch());)
    *p++ = c;
   *p = '\0';
   ungetch(c);
   return tokentype = NAME;
  } else
   return tokentype = c;
 }



 //parmdcl: parse a parameter declarator
 void parmdcl(void)
 {
  do{
   dclspec();
  }while (tokentype == ',');
  if(tokentype != ')')
   errmsg("missing ) in parameter declaration\n");
 }

 //dclspec: declaration specification
 void dclspec(void)
 {
  char temp[MAXTOKEN];
  temp[0] = '\0';
  gettoken();
  do{
   if(tokentype != NAME){
    prevtoken = YES;
    dcl();
   }else if(typedesc() == YES){
    strcat(temp," ");
    strcat(temp, token);
    gettoken();
   }else if(typeequal() == YES){
    strcat(temp," ");
    strcat(temp, token);
    gettoken();
   }else
    errmsg("unknown type parameter list\n");
  }while(tokentype != ',' && tokentype != ')');
  strcat(out,temp);
  if(tokentype == ',');
  strcat(out,",");
 }

 //typedesc: return yes if token is type-specifier
 int typespec(void)
 {
  static char *types[] = {
    "char",
    "int",
    "void"
  };
  char *pt = token;
  if(bsearch(&pt, types,sizeof(types)/sizeof(char *),
    sizeof(char *),compare) == NULL)
   return NO;
  else
   return YES;
 }

 //typeequal:return YES if token is a type qualifier
 int typeequal(void)
 {
  static char *typeq[] = {
    "const",
    "volatite"
  };
  char *pt = token;
  if(bsearch(&pt, typeq,sizeof(typeq)/sizeof(char *),
    sizeof(char *),compare) == NULL)
   return NO;
  else
   return YES;

 }

 //compare: compare two strings for bsearch
 int compare(char **s, char **s)
 {
  return strcmp(*s, *t);
 }
