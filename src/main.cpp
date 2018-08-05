#include <Application.hpp>

#include <stdexcept>
#include <iostream>

#include <InitData.hpp>
#include <Utility.hpp>
#include <plog/Log.h>
#include <plog/Appenders/DebugOutputAppender.h>

/* For overview of this program, see Neovim.hpp */

int main(int argc, char *argv[])
{
	static plog::DebugOutputAppender<plog::TxtFormatter> debugOutputAppender;
	plog::init(plog::verbose, &debugOutputAppender);

    Stealth();

    //file to open as supplied in the argument if any
    std::string filename;

    if (argc > 1)
        filename = std::string(argv[1]);

    //initializing init data
    auto initData = readInitData("neosfml.ini");
    //order matters
	if (!initData.font.loadFromFile(initData.pathToFont)) {
		LOGE << "no font";
		return 1;
	}
    initData.fileToOpen = filename;
    constructVideoMode(initData); //called after font is loaded

	try
	{
		Application app(initData);
		app.run();
	}
	catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
        std::cin.get();
	}
}
