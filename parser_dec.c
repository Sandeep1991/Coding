#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "xirmac.h" 
#include <sys/ioctl.h>
#include <ctype.h>

#define expand(op) "%02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",op[0],op[1],op[2],op[3],op[4],op[5],op[6],op[7], op[8],op[9],op[10],op[11],op[12],op[13],op[14],op[15],op[16],op[31]
#define ENC_OBJ 1
#define DEBUG_CRYPTO 1
/*
Key Lengths: 128 (bits)  = 16
Tag Lengths: 64 (bits)   = 8
IV Lengths: 104 (bits)   = 13
Plain Text Length: 1-32  = 32
AAD Length: 22-30        = 22-30
Prerequisite: AES     
*/

struct eo{
    //char key[33];
    unsigned int alen;         
    unsigned int plen;
    unsigned int tlen; 
    unsigned int enc_algo;
    unsigned int eflag;
    unsigned int ivlen;
    unsigned int key[16];
    unsigned int aad[32];
    unsigned int iv[16];
    unsigned int pt[32];
    unsigned int ct[64];       //40 is sufficient as clen = plen + tlen max tlen = 8; plen = 32
    unsigned int rsp[64];      
};

struct de{
    unsigned int alen;         
    unsigned int plen;
    unsigned int tlen; 
    unsigned int enc_algo;
    unsigned int ivlen;
    unsigned int eflag;
    unsigned int key[16];
    unsigned int aad[32];
    unsigned int iv[16];
    unsigned int ct[64];
    unsigned int pt[32];
    unsigned int rsp[64];
};

/*struct crypt{
    unsigned int key[16];                 //the aes encryption key
    unsigned int keylen;                  //this is 128 bits as we have selected the rsp files
    unsigned int datalen;                 //this is 128 bits as we have selected the rsp files   
    unsigned int pt[16];                  //the plain text value 
    uint legacy;                          //this should be set to 0 as CCMP is blocked for legacy devices
    unsigned int iv[0];                   //only 1st byte of value 104 bit “iv[0]” is formed using Packet Number(PN), Transmitter Address (TA) & priority bits in QoS.
    unsigned int ct[16];                  //store the expected cipher text too! (not required to be passed for AES-CCMP)
    unsigned int iv[16];                  //store the iv values apparently this too seems not required!
};*/

/*
struct ioctl_set_fips_values{
    struct ioctl_cmd cmd;
    struct crypt cryptObj;
};*/


/*struct ioctl_cmd {
u16 cmd;                                      //cmd code
s8  iface;                                    //network interface 0-15, -1 for all
s8  ssid;                                     //ssid 0-15, -1 for all
u16 len;                                      //length of command data, or length of buffer for status
} __attribute__ ((packed));
*/

typedef struct Ioctl_fips {
        struct ioctl_cmd cmd;
        struct ioctl_set_fips_values isfv;
    } Ioctl_fips;


//struct ioctl_set_fips_values ioctl_fips;
//struct crypt *cryp_obj;
//int cnt1 = 0; //keep track of the cnt of cryp_obj

/*void appendCrypto(struct crypt cobj)
{
    ioctl_fips.isfv.cryp_obj[cnt1].keylen = cobj.keylen;
    ioctl_fips.isfv.cryp_obj[cnt1].datalen = cobj.datalen;
    ioctl_fips.isfv.cryp_obj[cnt1].legacy = cobj.legacy;
    ioctl_fips.isfv.cryp_obj[cnt1].iv[0] = cobj.iv[0];
    memcpy(&ioctl_fips.isfv.cryp_obj[cnt1].key, &cobj.key, 64);
    memcpy(&ioctl_fips.isfv.cryp_obj[cnt1].iv, &cobj.iv, 64);
    memcpy(&ioctl_fips.isfv.cryp_obj[cnt1].pt, &cobj.pt, 64);
    memcpy(&ioctl_fips.isfv.cryp_obj[cnt1].ct, &cobj.ct, 64);
    cnt1++;
}*/

int sIoctl(Ioctl_fips ioctl_fips)
{
    int cr_mac_ctl, err;
    //struct ioctl_set_fips_values isfv;
    //struct crypt *cryp_obj;
    //ioctl_fips.isfv.num_cry = 1;
    //ioctl_fips.isfv.length = 128;
    //memcpy(isfv.cryptObj.key,cryp_obj.key,128);
    //int no_cry = (sizeof(struct ioctl_fips)-sizeof(struct ioctl_cmd))/sizeof(struct crypt);
    int no_cry = ioctl_fips.isfv.num_cry;
    int h = no_cry / 2; //here's where the decrypt object comes if the no of encry is same as decry
    cr_mac_ctl = open("/dev/mac-ctl", O_RDONLY | O_NONBLOCK | O_CLOEXEC);
    if (cr_mac_ctl < 0)
    {
      printf("ERROR: Could not open mac control device, /dev/mac-ctl\n");
      printf("Sent data is this:\n");
      printf("Total no of cry objects %d\n", no_cry);
      printf("%d %02x %02x %02x %02x %d %d %d %d\n",ioctl_fips.isfv.cryp_obj[0].eflag, ioctl_fips.isfv.cryp_obj[0].key[8],ioctl_fips.isfv.cryp_obj[0].iv[8],ioctl_fips.isfv.cryp_obj[0].pt[8], ioctl_fips.isfv.cryp_obj[0].ct[8],ioctl_fips.isfv.cryp_obj[0].keylen, ioctl_fips.isfv.cryp_obj[0].datalen, ioctl_fips.isfv.cryp_obj[0].iv[0], ioctl_fips.isfv.cryp_obj[0].legacy);
      printf("%02x %02x %02x %02x %d %d %d %d\n",ioctl_fips.isfv.cryp_obj[h].key[8],ioctl_fips.isfv.cryp_obj[h].iv[8],ioctl_fips.isfv.cryp_obj[h].pt[8], ioctl_fips.isfv.cryp_obj[h].ct[8],ioctl_fips.isfv.cryp_obj[h].keylen, ioctl_fips.isfv.cryp_obj[h].datalen, ioctl_fips.isfv.cryp_obj[h].iv[0], ioctl_fips.isfv.cryp_obj[h].legacy);
      //printf("%02x %02x %02x %02x %d %d %d %d\n",cryp_obj.key[8],cryp_obj.iv[8],cryp_obj.pt[8],cryp_obj.ct[8], cryp_obj.keylen, cryp_obj.datalen, cryp_obj.iv[0], cryp_obj.legacy);
      //printf("%02x %02x %02x %02x\n",cryp_obj.key[15],cryp_obj.iv[15],cryp_obj.pt[15],cryp_obj.ct[15]);
      exit(-1);
    }
    
    struct ioctl_cmd cmd;
    ioctl_fips.cmd.cmd = IOCTL_CMD_RUN_TEST;
    ioctl_fips.cmd.iface = 0;
    ioctl_fips.cmd.ssid =  0;
    ioctl_fips.cmd.len =   0;
    //ioctl_fips.isfv.num_cry = 128;
    //ioctl_fips.isfv.length = 128;
    /*ioctl_fips.isfv.cryp_obj.keylen = 128;
    ioctl_fips.isfv.cryp_obj.datalen = 128;
    ioctl_fips.isfv.cryp_obj.iv[0] = 0;
    ioctl_fips.isfv.cryp_obj.legacy = 0;
    memcpy(&ioctl_fips.isfv.cryp_obj.key, &cryp_obj.key, 64);
    memcpy(&ioctl_fips.isfv.cryp_obj.iv, &cryp_obj.iv, 64);
    memcpy(&ioctl_fips.isfv.cryp_obj.pt, &cryp_obj.pt, 64);
    memcpy(&ioctl_fips.isfv.cryp_obj.ct, &cryp_obj.ct, 64);
    */
    err = ioctl(cr_mac_ctl, ioctl_fips.cmd.cmd, &ioctl_fips);
    //err = ioctl(cr_mac_ctl, 176, isfv);
    close(cr_mac_ctl);
    printf("%d %02x %02x %02x %02x %d %d %d %d\n",ioctl_fips.isfv.cryp_obj[0].eflag,ioctl_fips.isfv.cryp_obj[0].key[8],ioctl_fips.isfv.cryp_obj[0].iv[8],ioctl_fips.isfv.cryp_obj[0].pt[8],ioctl_fips.isfv.cryp_obj[0].ct[8], ioctl_fips.isfv.cryp_obj[0].keylen, ioctl_fips.isfv.cryp_obj[0].datalen, ioctl_fips.isfv.cryp_obj[0].iv[0], ioctl_fips.isfv.cryp_obj[0].legacy);
    printf("%02x %02x %02x %02x %d %d %d %d\n",ioctl_fips.isfv.cryp_obj[h].key[8],ioctl_fips.isfv.cryp_obj[h].iv[8],ioctl_fips.isfv.cryp_obj[h].pt[8], ioctl_fips.isfv.cryp_obj[h].ct[8],ioctl_fips.isfv.cryp_obj[h].keylen, ioctl_fips.isfv.cryp_obj[h].datalen, ioctl_fips.isfv.cryp_obj[h].iv[0], ioctl_fips.isfv.cryp_obj[h].legacy);
    //printf("%02x %02x %02x %02x\n",cryp_obj.key[15],cryp_obj.iv[15],cryp_obj.pt[15],cryp_obj.ct[15]);
    //printf("%02x %02x %02x %02x \n", ioctl_fips.isfv.cryp_obj.key[8], ioctl_fips.isfv.cryp_obj.iv[8], ioctl_fips.isfv.cryp_obj.pt[8], ioctl_fips.isfv.cryp_obj.ct[8]);
    printf("%02x %02x %02x %02x\n",ioctl_fips.isfv.cryp_obj[h].rsp[0],ioctl_fips.isfv.cryp_obj[h].rsp[1],ioctl_fips.isfv.cryp_obj[h].rsp[2],ioctl_fips.isfv.cryp_obj[h].rsp[3],ioctl_fips.isfv.cryp_obj[h].rsp[4]);
    printf("IOCTL returned %d\n", err);
    /*printf("%02x %02x %02x %02x %d %d %d %d\n",cryp_obj.key[8],cryp_obj.iv[8],cryp_obj.pt[8],cryp_obj.ct[8], cryp_obj.keylen, cryp_obj.datalen, cryp_obj.iv[0], cryp_obj.legacy);
    printf("%02x %02x %02x %02x\n",cryp_obj.key[15],cryp_obj.iv[15],cryp_obj.pt[15],cryp_obj.ct[15]);
    printf("%02x %02x %02x %02x \n", ioctl_fips.isfv.cryp_obj.key[8], ioctl_fips.isfv.cryp_obj.iv[8], ioctl_fips.isfv.cryp_obj.pt[8], ioctl_fips.isfv.cryp_obj.ct[8]);
    printf("IOCTL returned %d\n", err);
    
    */
    
    if (err != 0)
    {
        exit(-1);
    }
    return err;
}
char* filter(char* in, char var)
{
    int i, n = sizeof(in),j=0;
    char *out;
    for(i=0;i<n;i++)
    {
        if(in[i]!=var) 
        {
            out[j] = in[i];
            j++;
        }
    }

    //printf("filter %s\n",out);
    return out;
}
void scpy(int *in, int *out)
{
    int i;
    for(i=0;i<sizeof(in);i++)
    {
        out[i] = in[i];
    }
}
void hex_str_to_arr(char *in, int *out, int len)
{
    int i=0,vout;
    for(;i<len;i++)
    {
        sscanf(in + i*2, "%02x", &vout);
        out[i] = vout;
    }
}

int churn_int(char *str,size_t len)
{
    char *token;
    token = strtok(str," ");
    token = strtok(NULL," =\n");
    printf("churn_int %s \n",token);
    return atoi(token);
}
int alen=0,plen=0,nlen=0,tlen=0;
int set_variables(char *line)
{
    char *pch;
    int fa=0,fp=0,ft=0,fn=0;
    pch = strtok(line,"[]=, \n");
    if(strcmp(pch,"Alen"))
        fa = 1;
    while(pch != NULL)
    {
        if(strcmp(pch,"Plen")==0)
            fp = 1;
        else if(strcmp(pch,"Nlen")==0)
            fn = 1;
        else if(strcmp(pch,"Tlen")==0)
            ft = 1;
        else
        {
            if(fa)
            alen = atoi(pch);
            if(fp)
            plen = atoi(pch);
            if(ft)
            tlen = atoi(pch);
            if(fn)
            nlen = atoi(pch);
            fa=0;fp=0;fn=0;ft=0;
        }
        pch = strtok(NULL,"[]=, \n");
    }
}
int main(int argc, char *argv[])
{
    struct eo seo[400];
    struct de deo[400];
    /*enc_algo
     1 => AES_ECB, 2 => AES_CBC, 3 => AES_CTR, 4 => AES_CCM, 5 => AES_CCMP
    */
    //struct crypt cobj;
    //char *tmp_path = getenv("XIRRUS_IMAGE");
    //char *file1 = "/etc/fips/CBCGFSbox128.rsp";
    //char *file1 = "/etc/fips/CBCVarTxt128.rsp";
    char *file1;int enc_algo=4;
    if(argc<3)
    {
        printf("Arguments are missing. Will be running KAT \n");
        file1 = "VADT128.txt";
    }
    else
    {
        file1 = argv[1];   
        enc_algo = atoi(argv[2]);
        printf("%s\n",argv[2]);
    }
    char filename[100]={};
    //strcat( filename, tmp_path);
    strcat( filename, file1);
    FILE *file = fopen (filename, "r");
    int i=0,j=0,f=0,cnt=0;
    unsigned int key[16], iv[16];
    printf("Check works %s",file);
    if(file != NULL)
    {
        char line[1024],garb[512],gb;
        //char alen[2],*falen,*fplen,*ftlen,*fivlen, plen[4], tlen[4], ivlen[4];
        //int vplen, valen, vtlen, vnlen;
        //int alen=0,plen=0,nlen=0,tlen=0;
        //printf("Passed the null check\n");
        while(fgets(line,sizeof(line),file) != NULL )
        {
            //printf("We are here!\n");
                if(strncmp(line,"[Alen",5)==0 &&!f)
                {
                    sscanf(line,"[Alen = %d, Plen = %d, Nlen = %d, Tlen = %d]",&alen,&plen,&nlen,&tlen);
                    printf("a/p/n/t lengths %d %d %d %d \n",alen,plen,nlen,tlen);
                }
                if(strncmp(line,"Key",3)==0 &&!f)
                {
                    deo[i].alen = alen;
                    deo[i].plen = plen;
                    deo[i].tlen = tlen;
                    deo[i].ivlen = nlen;
                    deo[i].enc_algo = enc_algo;
                    memset(deo[i].rsp,0,sizeof(deo[i].rsp));
                    //pch = strtok(NULL," ,.-[]=\n\t");
                    char buf[32];
                    sscanf(line ,"Key = %s",buf);
                    //int yj=0;
                    //for(;yj<8;yj++)
                    printf("Char buffer is %s\n",buf);
                    int num_o[32];
                    hex_str_to_arr(buf,num_o,32);
                    //printf("%d\n",num_o[0]);
                    memcpy(deo[i].key,num_o,sizeof(num_o));
                    memcpy(key,deo[i].key,sizeof(deo[i].key)); 
                #ifdef DEBUG_CRYPTO
                    int jx =0 ;
                    printf("%02x",deo[i].key[0]);
                    for(;jx < sizeof(deo[i].key)/sizeof(deo[i].key[0]); jx++) 
                        printf("%02x ",deo[i].key[jx]);  
                    printf("\n");
                #endif 
                }
                
                if(strncmp(line,"Nonce",5)==0&&!f)
                {
                    int num_o[32];
                    char buf[32];
                    sscanf(line ,"Nonce = %s",buf);
                    printf("This is the string value of the Nonce %s",buf);
                    hex_str_to_arr(buf,num_o,nlen*2);
                    memcpy(deo[i].iv,num_o,sizeof(num_o));
                    //memcpy(deo[i].iv,num_o,sizeof(num_o));
                    memcpy(iv,deo[i].iv,sizeof(deo[i].iv));
                #ifdef DEBUG_CRYPTO
                    int jx =0 ;
                    printf("Nonce is ");//,deo[i].iv[0]);
                    for(;jx < sizeof(deo[i].iv)/sizeof(deo[i].iv[0]); jx++) 
                        printf("%02x ",deo[i].iv[jx]);  
                    printf("\n");
                #endif 
                }
                if(strncmp(line,"Adata",5)==0 && !f)
                {
                    //pch = strtok(NULL," ,.-[]=\n");
                    deo[i].alen = alen;
                    deo[i].plen = plen;
                    deo[i].tlen = tlen;
                    deo[i].ivlen = nlen;
                    deo[i].enc_algo = enc_algo;
                    //VADT doesn't have Key or nonce defined for each once per case so add it here for all the struct
                    memcpy(deo[i].key,key,sizeof(key));
                    memcpy(deo[i].iv,iv,sizeof(iv));
                    memset(deo[i].rsp,0,sizeof(deo[i].rsp));
                    int num_o[32];
                    char buf[32];
                    sscanf(line ,"Adata = %s",buf);
                    /*if(deo[i].alen==0)
                        printf("AAD is 0 and we may not support!\n");
                    else
                    {*/   
                        if(deo[i].alen==0) //deo[i].alen=1;   
                            memset(deo[i].aad,0,32);
                        else                       
                        {
                            hex_str_to_arr(buf,num_o,deo[i].alen);
                            //scpy(num_o,deo[i].key);
                            memcpy(deo[i].aad,num_o,sizeof(num_o));
                        }
                        printf("This is aad[0] %d ",num_o[0]);
                        
                        //#ifdef DEBUG_CRYPTO
                        int jx =0 ;
                        printf("AAD is ");//%02x",deo[i].aad[0]);
                        for(;jx < sizeof(deo[i].aad)/sizeof(deo[i].aad[0]); jx++) 
                            printf("%02x ",deo[i].aad[jx]);  
                        printf("\n");
                        //#endif
                    //}
                }
                if(strncmp(line,"Payload",7)==0&&!f)
                {
                    int num_o[128];
                    char buf[128];
                    sscanf(line ,"Payload = %s",buf);
                    hex_str_to_arr(buf,num_o,plen*2);
                    memcpy(deo[i].pt,num_o,sizeof(num_o));
                    int jx =0 ;
                    printf("Payload is ");//%02x",deo[i].pt[0]);
                    for(;jx < sizeof(deo[i].pt)/sizeof(deo[i].pt[0]); jx++) 
                        printf("%02x ",deo[i].pt[jx]);  
                    printf("\n");
                }
                if(strncmp(line,"CT",2)==0 &&!f)
                {
                    int ctlen = deo[i].plen + deo[i].tlen;
                    int num_o[128];
                    char buf[128];
                    sscanf(line ,"CT = %s",buf);
                    printf("CT string is %s \n",buf);
                    //memset(deo[i].ct,0,sizeof(deo[i].ct));
                    hex_str_to_arr(buf,num_o,ctlen*2);
                    memcpy(deo[i].ct,num_o,sizeof(num_o));
                    //int arr[]={0xfb,0x79,0xb7,0x23,0x33,0x05,0x8c,0x63,0x15,0x3d,0xe4,0x44,0xb1,0x9c};
                    //memcpy(deo[i].ct,arr,sizeof(arr));
                    int jx =0 ;
                    printf("Cipher text is ");//%02x",deo[i].ct[0]);
                    for(;jx < sizeof(deo[i].ct)/sizeof(deo[i].ct[0]); jx++) 
                        printf("%02x ",deo[i].ct[jx]);  
                    printf("\n");
                    i++;cnt++;deo[i].eflag = 0;
                }
        
        }
        fputs("\n", stdout);
        fclose(file);
    }
    else
    {
        perror(filename);
    }
    printf("\nENCRYPT\n");
    int p=0;
    for(;p<i;p++)
    {
        printf("%02x %02x %02x %02x %02x %02x %02x\n" ,deo[p].enc_algo,deo[p].key[0],deo[p].iv[0],deo[p].pt[0],deo[p].ct[0],deo[p].aad[0],deo[p].alen);
        #ifdef ENC_OBJ
            printf("Key is  "expand(deo[p].key));
            printf("Nonce is "expand(deo[p].iv));
            printf("AAd is "expand(deo[p].aad));
            printf("PT is "expand(deo[p].pt));
            printf("CT is "expand(deo[p].ct));
        #endif
    }
    /*p=0;
    for(;p<j;p++)
    {
        printf("%02x %02x %02x %02x %02x\n",deo[p].enc_algo,deo[p].key[8],deo[p].iv[8],deo[p].pt[8],deo[p].ct[8]);
    }
    
        Filling the necessary information required for the AES-CCMP test in funwifi
    */
    int q=0;
    Ioctl_fips ioctl_fips;
    ioctl_fips.isfv.cryp_obj = malloc(sizeof(struct crypt) * cnt); //This will dynamically alter the size for array of crypt objects 
    ioctl_fips.isfv.num_cry = cnt;
    ioctl_fips.isfv.length = 16;
    //ioctl_fips = malloc(sizeof(struct ioctl_cmd) + sizeof(struct crypt)*12);
    int k=0;

    for(;q<i;q++)
    {
        /*struct crypt cobj;
        cobj.keylen = 16;                  //this is 128 bits as we have selected the rsp files
        cobj.datalen = 16;                 //this is 128 bits as we have selected the rsp files   
        cobj.legacy = 0;                          //this should be set to 0 as CCMP is blocked for legacy devices
        cobj.iv[0] = 0;                   //only 1st byte of value 104 bit “iv[0]” is formed using Packet Number(PN), Transmitter Address (TA) & priority bits in QoS.
        memcpy(&cobj.key, &deo[q].key, sizeof(deo[q].key));
        memcpy(&cobj.iv, &deo[q].iv, sizeof(deo[q].iv));
        memcpy(&cobj.pt, &deo[q].pt, sizeof(deo[q].pt));
        memcpy(&cobj.ct, &deo[q].ct, sizeof(deo[q].ct));
        */
        //printf("%lu\n",sizeof(deo[q].ct));
        //cryp_obj.keylen = 128;
        //cryp_obj.datalen = 128;
        //cryp_obj.iv[0] = 0; 
        //cryp_obj.legacy = 0;
        //appendCrypto(cobj);
        ioctl_fips.isfv.cryp_obj[k].eflag = 0;
        ioctl_fips.isfv.cryp_obj[k].keylen = 16;
        ioctl_fips.isfv.cryp_obj[k].datalen = 16;
        ioctl_fips.isfv.cryp_obj[k].legacy = 0;
        //ioctl_fips.isfv.cryp_obj[k].iv[0] = 0;
        ioctl_fips.isfv.cryp_obj[k].alen = deo[q].alen;
        ioctl_fips.isfv.cryp_obj[k].plen = deo[q].plen;
        ioctl_fips.isfv.cryp_obj[k].tlen = deo[q].tlen;
        ioctl_fips.isfv.cryp_obj[k].ivlen = deo[q].ivlen;
        ioctl_fips.isfv.cryp_obj[k].enc_algo = deo[q].enc_algo;//,sizeof(ioctl_fips.isfv.cryp_obj[k].enc_algo));
        memcpy(&ioctl_fips.isfv.cryp_obj[k].aad,&deo[q].aad,sizeof(ioctl_fips.isfv.cryp_obj[k].aad));
        memcpy(&ioctl_fips.isfv.cryp_obj[k].rsp,&deo[q].rsp,sizeof(ioctl_fips.isfv.cryp_obj[k].rsp));
        memcpy(&ioctl_fips.isfv.cryp_obj[k].key, &deo[q].key, sizeof(ioctl_fips.isfv.cryp_obj[k].key));
        memcpy(&ioctl_fips.isfv.cryp_obj[k].iv, &deo[q].iv, sizeof(ioctl_fips.isfv.cryp_obj[k].iv));
        memcpy(&ioctl_fips.isfv.cryp_obj[k].pt, &deo[q].pt, sizeof(ioctl_fips.isfv.cryp_obj[k].pt));
        memcpy(&ioctl_fips.isfv.cryp_obj[k].ct, &deo[q].ct, sizeof(ioctl_fips.isfv.cryp_obj[k].ct));
        //cnt1++;
        k++;

    }
    /*
    q=0;
    for(;q<j;q++)
    {
        ioctl_fips.isfv.cryp_obj[k].eflag = 0;
        ioctl_fips.isfv.cryp_obj[k].keylen = 16;
        ioctl_fips.isfv.cryp_obj[k].datalen = 16;
        ioctl_fips.isfv.cryp_obj[k].legacy = 0;
        ioctl_fips.isfv.cryp_obj[k].iv[0] = 0;
        ioctl_fips.isfv.cryp_obj[k].enc_algo = deo[q].enc_algo;//,sizeof(ioctl_fips.isfv.cryp_obj[k].enc_algo));
        memcpy(&ioctl_fips.isfv.cryp_obj[k].rsp,&deo[q].rsp,sizeof(ioctl_fips.isfv.cryp_obj[k].rsp));
        memcpy(&ioctl_fips.isfv.cryp_obj[k].key, &deo[q].key, sizeof(ioctl_fips.isfv.cryp_obj[k].key));
        memcpy(&ioctl_fips.isfv.cryp_obj[k].iv, &deo[q].iv, sizeof(ioctl_fips.isfv.cryp_obj[k].iv));
        memcpy(&ioctl_fips.isfv.cryp_obj[k].pt, &deo[q].pt, sizeof(ioctl_fips.isfv.cryp_obj[k].pt));
        memcpy(&ioctl_fips.isfv.cryp_obj[k].ct, &deo[q].ct, sizeof(ioctl_fips.isfv.cryp_obj[k].ct));   
        k++;
    }*/
    //printf("works here!\n");
    int sFlag = sIoctl(ioctl_fips);

    //printf("DECRYPT\n");
    //for(;i<7;i++)
    //{
    //    printf("%02x %02x %02x %02x\n",deo[i].key[0],deo[i].iv[0],deo[i].ct[0],deo[i].pt[0]);
    //}
    FILE *fp = fopen("/output_ccm.txt","w+");
    int xi=0;
    for(;xi<k;xi++)
    {
        fprintf(fp, "Result %d\n",xi);
        if(ioctl_fips.isfv.cryp_obj[xi].legacy==0)
        {
            fprintf(fp, "Pass \n");
            fprintf(fp, "%08x%08x%08x%08x \n",ioctl_fips.isfv.cryp_obj[xi].rsp[0],ioctl_fips.isfv.cryp_obj[xi].rsp[1],ioctl_fips.isfv.cryp_obj[xi].rsp[2],ioctl_fips.isfv.cryp_obj[xi].rsp[3]);
        }
        else
        {
            fprintf(fp, "Fail \n");
        }
    }
    fclose(fp);
    return 0;
}
