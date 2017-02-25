import cx_Oracle as cx
import os
import json
#import urllib2
import ssl
import requests
import socket
import paramiko 
import time
##Organization and site for the JSON must be populated from the DC

def SendJson(key,diction,mu):
	data = json.dumps({
"metricData": [
	{
    "metricGroup": "Oracle",
    "metricInstanceId": "Oracle1",
    "metricInstanceName": key,
    "metricName": diction[key][0],
    "metricAttribute": key,
    "metricValue": mu,
    "metricUnit": diction[key][4],
    "timestamp": TIME,
    "upperThreshold": diction[key][3],
    "lowerThreshold": diction[key][2],
    "serviceName": "Oracle",
      "resourceId": "192.168.128.81",
      "resourceIdType": "IPAddress",
      "resourceUniqueId": HOST_Name,
      "organization": "d1b8a7f3-f9b3-4960-b20c-4b2d0f8eb9be:FIXSTREAM",
      "site": "1a20da66-7a6d-4229-b8f1-4820fab2debe:US"
      
    },
    {
    "metricGroup": "MySQL",
    "metricInstanceId": "MySQL01",
    "metricInstanceName": "MySQL instance 1",
    "metricName": "MySQL url Cache Hit Rate",
    "metricAttribute": "cache_hit_rate",
    "metricValue": "6.8",
    "metricUnit": "count",
    "timestamp": "1487961446",
    "upperThreshold": 2.9,
    "lowerThreshold": 1.5,
    "serviceName": "Oracle",
      "resourceId": "192.168.128.81",
      "resourceIdType": "IPAddress",
      "resourceUniqueId": "meridian-nce1",
      "organization": "d1b8a7f3-f9b3-4960-b20c-4b2d0f8eb9be:FIXSTREAM",
      "site": "1a20da66-7a6d-4229-b8f1-4820fab2debe:US"
      
    }
]})


	#req.add_header('Content-Type', 'application/json')
	headers = {'Content-type': 'application/json'}
	req = requests.post('https://172.16.2.125/api/v2/performance?key=ea21b119-151e-4f21-8b71-3cbc367eba7f', data=data,headers=headers,verify=False)
	print (data)
	#req.add_header('Content-Type', 'application/json')
	#response = urllib.urlopen(req,json.dumps(data))
	print(req.status_code)



db1 = cx.connect('hr/hr@192.168.128.81:1521/XE')
dsn_tns = cx.makedsn('192.168.128.81', 1521, 'XE')
#print(dsn_tns)
cur = db1.cursor()
cur.execute('select distinct udm_sql_file from udm_metadata')
l=[]
for result in cur:
	l.append(result[0])
cur.execute('select * from udm_metadata')

diction = {}
for res in cur:
	lst=[]
	for i in range(1,len(res)):
		lst.append(res[i])
	diction[res[0]]=lst

cur.close()
#print diction['STUCK']

ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
ssh.connect('192.168.128.81', username="oracle", password="oracle")
HOST_Name = str(socket.gethostbyaddr('192.168.128.81'))
HOST_Name = HOST_Name[2:]
#HOST_Name = ''.join(HOST_Name)
HOST_Name = HOST_Name.split('.')
HOST_Name = HOST_Name[0]
TIME = str(int(time.time()))
sftp = ssh.open_sftp()
sql_file_name = []
for file_name in l:
	localpath = file_name   #'order.sql'
	sql_file_name.append(localpath)
	remotepath = '/u01/app/oracle/UDM/' + file_name   #/order_value_alerts.sql
	sftp.get(remotepath, localpath)
sftp.close()
ssh.close()

###Here starts the SQL running #######
for sfile in sql_file_name:
	s_file = open(sfile, 'r')
	fStr =''
	for line in s_file:
		fStr = fStr + line.replace('\n',' ')
	sql_cmds = fStr.split(';')
	#sql_cmds = ["SELECT * from employees","SELECT * from employees"]
	db_con = cx.connect('hr/hr@192.168.128.81:1521/XE')
	dsn_tns = cx.makedsn('192.168.128.81', 1521, 'XE')
	cur = db_con.cursor()
	#print sql_cmds,type(sql_cmds)
	#print sql_cmds, type(sql_cmds)

	#for sql_cmd in sql_cmds:
	#	print sql_cmd
		
	#for i in range(len(lists)):
	#    grades.append(lists[i].strip('\n'))

	if len(sql_cmds) > 1:
		for sql_cmd in sql_cmds:
			k = sql_cmd.replace(' ','')
			if k != '': 
				cur.execute(sql_cmd)
			#print sql_cmd

	#cur.execute(sql_cmds[0])
	for j in cur:
		#print j[0], j[1]
		if j[0] in diction:
			SendJson(j[0],diction,j[1])
