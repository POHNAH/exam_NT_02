vuser_init()
{

	lr_param_sprintf("US", userSess);
	lr_output_message(lr_eval_string("{US}"));
	
	web_submit_data("login.pl_2", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={US}", ENDITEM, 
		"Name=username", "Value={login}", ENDITEM, 
		"Name=password", "Value={pass}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=73", ENDITEM, 
		"Name=login.y", "Value=12", ENDITEM, 
		LAST);
	                  
	vuser_end();

	return 0;
}
