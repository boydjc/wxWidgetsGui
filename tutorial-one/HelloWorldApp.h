#ifndef HELLOWORLDAPP_H
#define HELLOWORLDAPP_H

class HelloWorldApp : public wxApp {
	public: 
		virtual bool OnInit();
};

DECLARE_APP(HelloWorldApp)

#endif
