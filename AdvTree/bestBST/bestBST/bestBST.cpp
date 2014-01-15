#include <iostream>
//��̬�滮�㷨������Ŷ�������������
//�������:a[]�ڲ�����Ȩ,b[]�ⲿ����Ȩ,n�����
//�������:**wȨ���ܺ�,**r���������,**c�������Ĵ���

#define N 4

void OptimalBST(int a[], int b[], int n, int c[N+1][N+1], int r[N+1][N+1], int w[N+1][N+1]) {
	int i, j, d;
	for (i = 0; i <= n; i++)   						// ��������������
		for (j = 0; j <= n; j++) {
			c[i][j] = 0;		  
			r[i][j] =0;
			w[i][j] = 0;
		}
	// ��ʼ����ȷ��ÿһ����Ȩ��w[i,j]
	for (i = 0; i <= n; i++) {
		w[i][i] = b[i];
		//���Ȩ��w[i.j]
		for (j = i+1; j <= n; j++)
			w[i][j] = w[i][j-1] + a[j] + b[j];
	}

	//ȷ��һ��������Ѷ�����������һ������c[j-1, j]���Ƕ�Ӧ��w[j-1, j]
	for (j = 1; j <= n; j++) {
		c[j-1][j] = w[j-1][j];
		r[j-1][j] = j;
	}

	//ȷ��d��������Ѷ�����
	int m, k0, k;
	for (d = 2; d <= n; d++) {
		for (j = d; j <= n; j++){
			i = j - d;
			m = c[i+1][j];
			k0 = i + 1;         					// ��Ki+1Ϊ��
			for (k = i+2; k <= j; k++) {
				if (c[i][k-1] + c[k][j] < m) {  		// ��̬�滮�ĺ��Ĳ���
					m = c[i][k-1] + c[k][j];  		// �ѵ�ǰ��С��¼����
					k0 = k;
				}
			}
			c[i][j] = w[i][j] + m;   				// ��¼��СȨ
			r[i][j] = k0;         					// ��¼����
		}
	}
}


void main()
{
	//�����½̲�ͼ12.27��Ѷ�����
	int a[N+1]={0,1,5,4,3};
	int b[N+1]={5,4,3,2,1};
	int c[N+1][N+1];
	int r[N+1][N+1];
	int w[N+1][N+1];
	int n=N;
	//������Ѷ�����
	OptimalBST(a,b,n,c,r,w);
	for(int i=0;i<=n;i++)
	{

		for(int j=0;j<i;j++)
			std::cout<<"  ";
		std::cout<<"0 ";
		for(int j=i+1;j<=n;j++)
		{
			std::cout<<r[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	system("pause");
}
