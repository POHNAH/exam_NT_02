Enter()
{
    web_reg_save_param("US",
    	"LB=userSession\" value=\"", 
    	"RB=\"/>", 
    	LAST);
	
 	web_url("webtours",
		"URL=http://localhost:1080/webtours", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	userSess = lr_eval_string("{US}");
//	lr_output_message(userSess);
	                  
	return 0;
}
