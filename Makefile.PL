use ExtUtils::MakeMaker;

WriteMakefile(
 	'NAME'	=> q(SGI::syssgi),
	'VERSION' => '1.001',
    	'OBJECT' => 'syssgi.o syssgi_wrap.o'

);
