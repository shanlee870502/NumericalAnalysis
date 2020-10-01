#include <iostream>
#include <math.h>
#define EPSILON   0.000001
using namespace std;

/*********************************************
function:
f(x, y) = ((x-3)^2)/25) + ((y-4)^2/16) - 1 = 0
g(x, y) = y - x^2 - 2*x - 1 = 0
***********************************************/

/***function ***/
double f(double x, double y)
{
    return ((x-3)*(x-3)/25) + ((y-4)*(y-4)/16) - 1;
}

double g(double x, double y)
{
    return y - x*x - 2*x - 1;
}

/*** first derivatives of f(x,y) ***/
double fx(double x, double y)
{
    return (2.0*(x-3.0)) / 25.0; 
}

double fy(double x, double y)
{
    return (2.0*(y-4.0)) / 16.0;    
}

/*** first derivatives of g(x,y) ***/
double gx(double x, double y)
{
    return -2.0*x - 2.0;
}

double gy(double x, double y)
{
    return 1.0;
}

void newton2D(double *x, double *y)
{
    //cout<<*x<<*y<<endl;
    int i=0;
    double err, xnew, xold, ynew, yold;
    double fdx, fdy, gdx, gdy, Delta; // Delta: determinent of jacobian matrix
    double fold, gold;
    
    //initial conditions
    xold = *x;
    yold = *y;

    // function value
    fold = f(xold, yold);
    gold = g(xold, yold);
    
    //derivative value
    fdx = fx(xold, yold);
    fdy = fy(xold, yold);
    gdx = gx(xold, yold);
    gdy = gy(xold, yold);
    
    //determinent of Jacobian matrix
    Delta = fdx * gdy - fdy * gdx;

    //Update root
    xnew = xold - ( ( gdy * fold - fdy * gold)/Delta);
    ynew = yold - ( ( -gdx * fold + fdx * gold)/Delta);
    
    //Compute 2-norm error vector
    double err_total = pow(xnew - xold,2) + pow(ynew-yold,2);
    
    err = sqrt(err_total);
    
    printf("      i          xn              yn              2-norm           f(x,y)           g(x,y)\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("     %3d \t%lf \t%lf \t   ---            %lf\t %lf\t  \n", i, xold, yold, f(xold,yold),g(xold,yold));

    i +=1;                     
    while(err> EPSILON)
    {
        printf("     %3d \t%lf \t%lf \t %lf\t %lf\t %lf\t \n", i, xnew, ynew, err, f(xnew,ynew),g(xnew,ynew));

        xold = xnew; // Save current value.
        yold = ynew;                                                                                            
        //Update the root.
        fold = f(xold, yold);
        gold = g(xold, yold);
        fdx = fx(xold, yold);
        fdy = fy(xold, yold);
        gdx = gx(xold, yold);
        gdy = gy(xold, yold);
        
        Delta = fdx*gdy - fdy*gdx;

        xnew = xold - (gdy*fold - fdy*gold)/Delta;
        ynew = yold - (-gdx*fold + fdx*gold)/Delta;
        //cout<<"**"<< xnew <<"  "<< ynew<<endl;
        //Compute the 2-norm of the error vector.
        err_total = pow(xnew - xold,2) + pow(ynew-yold,2);
        
        err = sqrt(err_total);
       
        if(i == 20) break;
        i ++;
    }
    if(err>EPSILON) cout<<">> Diverge"<<endl;
    else cout<<">> Converge"<<endl; 

    printf("==============================================================================================\n");
}   



int main(void)
{
    double x, y;

    cout<<"Initial Points:  \n"<<"x= ";
    cin>>x;
    cout<<"y= ";
    cin>>y;
    cout<<"\n";
    newton2D(&x, &y);  
    
    cout<<"4 other Initial Points"<<endl;
    int round_n = 4;
    while(round_n --)
    {
        cout<<"Initial Points:  \n"<<"x= ";
        cin>>x;
        cout<<"y= ";
        cin>>y;
        cout<<"\n";
        newton2D(&x, &y);      
    } 
}
/*
3.01
3.99
-5
10
-5
-5
5
10
5
-5
*/

