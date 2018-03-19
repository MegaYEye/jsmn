#include <jsmn.h>
#include <stdio.h>
void get_json_val(jsmntok_t *t,int len, char *json,char *key, char * val_out,int res_len) {
	int i,j,k;
	for (i=0;i<res_len;i++) val_out[i]=0;

	for (i = 1; i < len; i++) {
		if (jsoneq(json, &t[i], key) == 0) {
	  		for(k=0,j=t[i+1].start  ;j<t[i+1].end && k<res_len-1;  j++) 
	  			val_out[k++]=json[j];
	  		val_out[j]=0;
	  		return;
	  	}
	}
}

unsigned char chksum(char * str) {
	int i=0;
	unsigned int x=0;
	for(i=0;str[i]!=0;i++) {
		x += (unsigned char)str[i];
	}
	return (unsigned char)(x&0xff);
}
int main() {
	char * json="{\"distance\":\"123\"}";
	char * json2="{\"SUCCESS\":\"OK\",\"DDD\":123321}";
	int i,j,k;
	int r;
	jsmn_parser p;
    jsmntok_t t[128]; 
    char result[100];

    jsmn_init(&p);
    
    r = jsmn_parse(&p, json, strlen(json), t, sizeof(t)/sizeof(t[0]));

	get_json_val(t,r,json,"distance",result, sizeof(result));

	printf("%s\n",result);

	jsmn_init(&p);

    r = jsmn_parse(&p, json2, strlen(json2), t, sizeof(t)/sizeof(t[0]));

	get_json_val(t,r,json2,"SUCCESS",result, sizeof(result));
 
	printf("%s\n",result);

	get_json_val(t,r,json2,"DDD",result, sizeof(result));
 
	printf("%s\n",result);

	get_json_val(t,r,json2,"SUCCESS",result, sizeof(result));
 
	printf("%s\n",result);
	printf("%d\n",chksum(json2));


	return 0;
}