
void logBuffer(int level,char *hdr,char *buf,int len, int Ishex)
{
	int column_len=80;
	char log_buf[160+100], *lptr;
	int msg_idx;

	lptr=&log_buf[0];
	char *for_string= Ishex?"%02X":"%c";
	
	for(msg_idx=0;msg_idx<len;msg_idx++)
	{
		if(msg_idx%column_len ==0)
		{
			lptr=&log_buf[0];
			if(hdr!= NULL)
				lptr+=sprintf(lptr,"%s:",hdr);
		}
		lptr+=sprintf(lptr,for_string,buf[msg_idx]);
		if((msg_idx%column_len)==(column_len-1))
		{
			lptr+=sprintf(lptr,"\n");
			logMessage(level, "%s",log_buf);
			lptr=&log_buf[0];
		}	
	}	
	if(lptr != (&log_buf[0]))
	{
		lptr+=sprintf(lptr,"\n");
		logMessage(level, "%s",log_buf);
	}
}
