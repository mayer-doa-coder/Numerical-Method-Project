#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"******************Welcome to Equation Solver******************"<<endl<<endl;
    cout<<"What type of equation do you want to solve?"<<endl;
    cout<<"1. Solve Linear Equations"<<endl;
    cout<<"2. Solve Non-Linear Equations"<<endl;
    cout<<"3. Solve Differential Equations"<<endl;
    cout<<"4. Matrix Inversion"<<endl;

    int choice;
    cin>>choice;
    switch (choice)
    {
        case 1:
        {
            int n;
            cout<<"Enter the number of equations: ";
            cin>>n;
            vector<vector<double>> coefficient(n, vector<double>(n,0.0));
            vector<double> rhs(n),initial(n,0.0);
            cout<<"Enter the Coefficients"<<endl;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cin>>coefficient[i][j];
                }
            }
            cout<<"Enter the RHS"<<endl;
            for(int i=0;i<n;i++)
                cin>>rhs[i];
            cout<<"Select the method you want to use: "<<endl;
            cout<<"1. Jacobi Iterative Method"<<endl;
            cout<<"2. Gauss-Seidel Iterative Method"<<endl;
            cout<<"3. Gauss Elimination Method"<<endl;
            cout<<"4. Gauss-Jordan Method"<<endl;
            cout<<"5. LU Factorization"<<endl;
            int method;
            cin>>method;
            cout<<endl;
            if(method==1)
                Jacobi_Iterative_Method(coefficient,rhs,initial);
            else if(method==2)
                Gauss_Siedel_Method(coefficient,rhs,initial);
            else if(method==3)
            {
                vector<vector<double>> A1=Gauss_Elimination_Method(n,coefficient,rhs);
                cout<<"After Gaussian Elimination: "<<endl;
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n+1;j++)
                        cout<<setw(10)<<setprecision(2)<<A1[i][j]<<" ";
                    cout<<endl;
                }   
                cout<<endl;
            }
            else if(method==4)
            {
                vector<vector<double>> A1=Gauss_Elimination_Method(n,coefficient,rhs);
                cout<<"After Gaussian Elimination: "<<endl;
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n+1;j++)
                        cout<<setw(10)<<setprecision(2)<<A1[i][j]<<" ";
                    cout<<endl;
                }   
                cout<<endl;
                vector<vector<double>> A2=Gauss_Jordan_Method(n,A1);
                cout<<"After Jordan Elimination: "<<endl;
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n+1;j++)
                        cout<<setw(10)<<setprecision(2)<<A2[i][j]<<" ";
                    cout<<endl;
                }
                cout<<endl;
                vector<vector<double>> A3=row_echelon(n,A2);
                cout<<"After Row Echelon form: "<<endl;
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n+1;j++)
                        cout<<setw(10)<<setprecision(2)<<A3[i][j]<<" ";
                    cout<<endl;
                }
            }
            else if(method==5)
                LU_Factorization(coefficient,rhs,initial);
            break;
        }
        case 2:
        {
            cout<<"Select the method you want to use: "<<endl;
            cout<<"1. Bi-Section Method"<<endl;
            cout<<"2. Newton-Raphson Method"<<endl;
            cout<<"3. Secant Method"<<endl;
            cout<<"4. False Position Method"<<endl;
            int method;
            cin>>method;
            int degree;
            cout<<"Enter the degree of the polynomials: ";
            cin>>degree;
            vector<double> coefficients(degree+1),deriCoefficient(degree);
            cout<<"Enter the coefficients:"<<endl;
            for(int i=0;i<=degree;i++)
            {
                cin>>coefficients[i];
            }
            if(method==1)
            {
                double a,b;
                cout<<"Enter interval [a,b]: ";
                cin>>a>>b;
                double root=Bi_Section_Method(degree,coefficients,a,b);
                cout<<"Root: "<<root<<endl;
            }
            else if(method==2)
            {
                for(int i=0;i<degree;i++)
                {
                    deriCoefficient[i]=coefficients[i]*(degree-i);
                }
                double x0;
                cout<<"Enter initial guess: ";
                cin>>x0;
                double root=Newton_Raphson_Method(degree,coefficients,deriCoefficient,x0);
                cout<<"Root: "<<root<<endl;
            }
            else if(method==3)
            {
                double x0,x1;
                cout<<"Enter two initial guesses: ";
                cin>>x0>>x1;
                double root= Secant_Method(degree,coefficients,x0,x1);
                cout<<"Root: "<<root<<endl;
            }
            else if(method==4)
            {
                double a,b;
                cout<<"Enter interval [a,b]: ";
                cin>>a>>b;
                double root= False_Position_Method(degree,coefficients,a,b);
                cout<<"Root: "<<root<<endl;
            }
            break;
        }
        case 3:
        {
            Runge_Kutta_Method();
            break;
        }
        case 4:
        {
            Matrix_Inversion();
            break;
        }
        default:
        {
            cout<<"Invalid Response. Try Again! "<<endl;
            break;
        }
    }
}
