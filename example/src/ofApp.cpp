#include "ofMain.h"

#include "ofxGlobalContext.h"

// super simple example

class MyContext : public ofxGlobalContext::Context
{
public:
	
	MyContext()
	{
		cout << "setup MyContext" << endl;
	}
	
	void update()
	{
		cout << "update MyContext" << endl;
	}
	
};


// source context

class MyVideoContext : public ofxGlobalContext::Context
{
public:
	
	ofVideoGrabber video;
	
	MyVideoContext(int w, int h)
	{
		video.initGrabber(w, h);
	}
	
	void update()
	{
		video.update();
	}
};


// effect context

template <typename T>
class MyInvertVideoContext : public ofxGlobalContext::Context
{
public:
	
	typedef T Video;
	
	ofImage image;
	int counter;
	
      MyInvertVideoContext()
	{
		Video* o = $Context(Video);
		image.allocate(o->video.getWidth(), o->video.getHeight(), OF_IMAGE_COLOR);
		
		counter = 0;
	}
	
	void update()
	{
		// get global instance of Video
		ofPixels &video_pix = $Context(Video)->video.getPixelsRef();
		
		for (int y = 0; y < image.getHeight(); y++)
		{
			for (int x = 0; x < image.getWidth(); x++)
			{
				ofColor c = video_pix.getColor(image.getWidth() - x - 1, y);
				
				// some operation
				if ((counter % 3) == 0)
					swap(c.r, c.b);
				
				if ((counter % 5) == 0)
					swap(c.b, c.g);
				
				if ((counter % 15) == 0)
					swap(c.g, c.r);
				
				image.setColor(x, y, c);
			}
		}
		
		// and update image
		image.update();
		
		counter++;
	}
};

class ofApp : public ofBaseApp
{
public:
	
	void setup()
	{
		ofSetFrameRate(60);
		ofSetVerticalSync(true);
		ofBackground(0);
		
		// register contexts
		ofxGlobalContext::Manager::defaultManager().createContext<MyContext>();
		ofxGlobalContext::Manager::defaultManager().createContext<MyVideoContext>(640, 480); // with constructor arguments
		ofxGlobalContext::Manager::defaultManager().createContext<MyInvertVideoContext<MyVideoContext> >(); // with template
	}
	
	void update()
	{
		// update all registered context
		ofxGlobalContext::Manager::defaultManager().update();
	}
	
	void draw()
	{
		$Context(MyVideoContext)->video.draw(0, 0);
		$Context(MyInvertVideoContext<MyVideoContext>)->image.draw(640, 0);
	}

	void keyPressed(int key)
	{
	}

	void keyReleased(int key)
	{
	}
	
	void mouseMoved(int x, int y)
	{
	}

	void mouseDragged(int x, int y, int button)
	{
	}

	void mousePressed(int x, int y, int button)
	{
	}

	void mouseReleased(int x, int y, int button)
	{
	}
	
	void windowResized(int w, int h)
	{
	}
};


int main(int argc, const char** argv)
{
	ofSetupOpenGL(1280, 480, OF_WINDOW);
	ofRunApp(new ofApp);
	return 0;
}
