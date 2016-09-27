#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	char str[10000];

	while(scanf("%s",str)!=EOF){

		//printf("%s  :  " ,str );

		int len=strlen(str);

		int flag=0;
		int cpt=0;

		for(int i=0;i<len;i++){
			char ch=str[i];

			if(ch>='A' && ch<='Z'){
				cpt=1;
			}else if(ch=='_'){
				flag=1;

				if(i+1<len){
					if(str[i+1]>='0' && str[i+1]<='9'){
						flag=5;
						break;		
					}
				}
			}

			if(!( ( ch>='a' && ch<='z')  || (ch>='0' && ch<='9') || (ch>='A' && ch<='Z') || (ch=='_') )){
				flag=5;
				break;
				
			}

			if(i!=0){
				if(str[i]=='_'&& str[i-1]=='_'){
					flag=5;
					break;
				}
			}

		}

		if( (str[0]<'a' || str[0]>'z') ){
			printf("Error!\n");
			continue;

		}

		if( (str[0]>='0' && str[0]<='9') || (str[0]>='A' && str[0]<='Z') ||str[len-1]=='_' || str[0]=='_' || flag==5){

			printf("Error!\n");
			continue;

		}

		if(flag==1 && cpt==1){
			printf("Error!\n");
		}else{
			if(cpt==1){

				for(int i=0;i<len;i++){
					char ch=str[i];

					if(ch>='A' && ch<='Z'){
						printf("_%c", 'a'+ch-'A');
					}else{
						printf("%c",ch );
					}

				}

			}else{
				
				for(int i=0;i<len;i++){
					char ch=str[i];

					if(ch=='_'){
						i++;
						ch=str[i];

						if(ch>='a' && ch<='z'){
							printf("%c", 'A'+ch-'a');

						}else{
							printf("Error!\n");
							break;
						}

						continue;
					}

					printf("%c", ch );

				}

			}
				printf("\n");

		}

	}

}