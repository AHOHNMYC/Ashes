#import <mach-o/dyld.h>
#import <cstdlib>
#import <string>

#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#pragma clang diagnostic ignored "-Wmissing-prototypes"

void * CGLGetProcAddress( const char * name )
{
	std::string symbolName = std::string( "_" ) + name;
	NSSymbol symbol = nullptr;

	if (NSIsSymbolNameDefined( symbolName.c_str() ) )
	{
		symbol = NSLookupAndBindSymbol( symbolName.c_str() );
	}

	return ( symbol
		? NSAddressOfSymbol( symbol )
		: nullptr );
}
