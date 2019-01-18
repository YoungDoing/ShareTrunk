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
	//将字符串数组倒序排列并且转化为int 类型 
	
	
	
	for(i=0;i<lenmax+1;i++){
		f[i]=A[i]+B[i];
		}	
	for(i=0;i<lenmax+1;i++){
		if(f[i]>9){
			f[i]%=10;
			f[i+1]+=1;
	}
}
	return f;//算出两个大数之和，不过是倒序的输出结果	
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
	//依次输入n组的a，b，c，三个大数 
	for(i=0;i<n;i++){
	lentha[i]=strlen(a[i]);
    lenthb[i]=strlen(b[i]);
	lenmax[i]=lentha[i]>lenthb[i]?lentha[i]:lenthb[i];
}
//依次计算n组输入的数字长度，用于后续比较大小 

	for(i=0;i<n;i++){
		plus(a[i],b[i],f);
		if(f[lenmax[i]]) lenmax[i]+=1;//如果a，b两数之和的最高位不为零，说明有进位，和的位数在lenmax的基础上+1 
		if(lenmax[i]>strlen(c[i])) tos[i]=1;//比较和的位数和输入大数的位数，用来比较其大小 
		else if(lenmax[i]<strlen(c[i])) tos[i]=0;
		else{//如果位数相同，进行如下比较 
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
		if(flag==1) tos[i]=0;//如果每一位都相同，则flag数值不变 
	}
}
	
	
	
    for(i=0;i<n;i++){
    	if(tos[i]==1) printf("Case #%d:true",i+1);
    	else printf("Case #%d:false",i+1);
    	if(i!=n-1) printf("\n");
	}	//利用tos数组存储n组数据比较大小的结果，现在输出其结果 
	return 0;		
}
