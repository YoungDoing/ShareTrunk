#include <stdio.h>
#include<stdlib.h>
#include<string.h>
    
	
    int *plus(char a[],char b[],int f[]){
    int lentha=strlen(a);
	int lenthb=strlen(b);
	int lenmax=lentha>lenthb?lentha:lenthb;
	int A[lentha],B[lenthb];
	int i;
	
	
	for(i=0;i<lentha;i++){
		A[i]=a[lentha-i-1]-'0';
	}
	for(i=0;i<lenthb;i++){
		B[i]=b[lenthb-i-1]-'0';
	}
	//���ַ������鵹�����в���ת��Ϊint ���� 
	
	
	
	for(i=0;i<lenmax+1;i++){
		f[i]=A[i]+B[i];
		}	
	for(i=0;i<lenmax+1;i++){
		if(f[i]>9){
			f[i]%=10;
			f[i+1]+=1;
	}
}
	return f;//�����������֮�ͣ������ǵ����������	
}


int main(){
	int n,i,j;
	scanf("%d",&n);
	int lentha[n],lenthb[n],lenmax[n],tos[n],f[12];
	char a[n][12],b[n][12],c[n][12];
	int flag=1;
	
	
	for(i=0;i<n;i++){
		scanf("%s %s %s",&a[i],&b[i],&c[i]);
	}
	//��������n���a��b��c���������� 
	for(i=0;i<n;i++){
	lentha[i]=strlen(a[i]);
    lenthb[i]=strlen(b[i]);
	lenmax[i]=lentha[i]>lenthb[i]?lentha[i]:lenthb[i];
}
//���μ���n����������ֳ��ȣ����ں����Ƚϴ�С 

	for(i=0;i<n;i++){
		plus(a[i],b[i],f);
		if(f[lenmax[i]]) lenmax[i]+=1;//���a��b����֮�͵����λ��Ϊ�㣬˵���н�λ���͵�λ����lenmax�Ļ�����+1 
		if(lenmax[i]>strlen(c[i])) tos[i]=1;//�ȽϺ͵�λ�������������λ���������Ƚ����С 
		else if(lenmax[i]<strlen(c[i])) tos[i]=0;
		else{//���λ����ͬ���������±Ƚ� 
		for(j=strlen(c[i])-1;j>-1;j--){
			if(f[j]>c[i][j]-'0') {
				tos[i]=1;
				flag=0;
				break;
			}else if(f[j]<c[i][j]-'0'){
				tos[i]=0;
				flag=0;
				break;
			}
		}
		if(flag==1) tos[i]=0;//���ÿһλ����ͬ����flag��ֵ���� 
	}
}
	
	
	
    for(i=0;i<n;i++){
    	if(tos[i]==1) printf("Case #%d:true",i+1);
    	else printf("Case #%d:false",i+1);
    	if(i!=n-1) printf("\n");
	}	//����tos����洢n�����ݱȽϴ�С�Ľ��������������� 
	return 0;		
}
