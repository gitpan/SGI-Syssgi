package SGI::syssgi;

use strict;
use Carp;
use vars qw($VERSION @ISA @EXPORT @EXPORT_OK);

require Exporter;
require DynaLoader;
require AutoLoader;

@ISA = qw(Exporter DynaLoader);
@EXPORT = qw( );
$VERSION = '1.001';

bootstrap SGI::syssgi;

1;
__END__

=head1 NAME

syssgi - Perl inteface to the IRIX syssgi system call

=head1 SYNOPSIS

use syssgi;

  $sysid = syssgi::_SGI_SYSID();
  $process_name = syssgi::_SGI_RDNAME($process_id, $bufferspace);
  $variable_value = syssgi::_SGI_GETNVRAM($variable_name);
  $success = syssgi::_SGI_SETNVRAM($variable_name, $new_value);
  $success = syssgi::_SGI_SETLED(1);
  $success = syssgi::_SGI_SSYNC();
  $success = syssgi::_SGI_BDFLUSHCNT($kernel_write_delay);
  $success = syssgi::_SGI_SET_AUTOPWRON($startup_time);
  $timetrim = syssgi::_SGI_GETTIMETRIM();
  $success = syssgi::_SGI_SETTIMETRIM($new_timetrim);

=head1 REQUIRES

Perl5.004, Silicon Graphics IRIX 6.5.x

=head1 DESCRIPTION

Perl interface to the IRIX specific syssgi system call. This allows for easy 
access to IRIX system functions from Perl. For further documentation on this 
API , see I<man syssgi>.

=head1 MAIN METHODS

=over 4

=item B<_SGI_SYSID>

Returns the unique system identifier as characters.

=item B<_SGI_SETLED (> I<led_state> B<)>

Turns on or off the led on the machine, this only works for some machines.
Platforms reported to work so far is: Indigo2 and O2. A I<led_state> of 1 turns
the led on, 0 turns the led off.

=item B<_SGI_RDNAME (> I<process_id, bufferspace> B<)>

Returns the process name for the pid specified by I<process_id>. I<bufferspace>
characters is reserved and used in the name acquisition, if the process name is
larger than his buffer, it will be truncated.

=item B<_SGI_GETNVRAM (> I<variable_name> B<)>

Retrieves the value associated with the by I<variable_name> specified prom
environment variable.

=item B<_SGI_SETNVRAM (> I<variable_name, new_value> B<)>

Alters the value associated with the by I<variable_name> specified prom 
environment variable to the by I<new_value> specified value.

=item B<_SGI_SSYNC>

Synchronously flush out all delayed write buffers.

=item B<_SGI_BDFLUSHCNT (> I<kern_write_delay> B<)>

Delays the kernel from writing for <kern_write_delay> seconds and returns 
the previous flush delay. The normal flush delay will be applied after
this call. This is intended to be used in conjunction with _SGI_SSYNC on
uniprocessor systems to keep the kernel from performing unwanted disk
activity.

=item B<_SGI_SET_AUTOPWRON (> I<power_on> B<)>

Sets the time at when the system is to automatically power up again. This
only works if the machine is powered off at this time. It is also only
implemented on the following: platforms: Octane (2?), Indy, Indigo2 and 
Challenge M.

=item B<_SGI_GETTIMETRIM>

Returns the current timetrim value. The system clock is adjusted every
second by the signed number of nanoseconds specified by this parameter.

=item B<_SGI_SETTIMETRIM (> I<timetrim_value> B<)>

Change the timetrim value from the value originally configued in:
/var/sysgen/mtune/kernel.

=back

=head1 VARIABLES

=item syssgi::NVRAM_INITSTATE

The initstate nvram environment variable. Stringvalue.

=item syssgi::NVRAM_PATH

The path nvram environment variable. Stringvalue.

=item syssgi::NVRAM_SHOWCONFIG

The path showconfig environment variable. Stringvalue.

=item syssgi::NVRAM_SWAP

The swap nvram environment variable. Stringvalue.

=item syssgi::NVRAM_VERBOSE

The verbose nvram environment variable. Stringvalue.

=head1 AUTHORS

Daniel Gustafson B<daniel@hobbit.se>

=head1 SEE ALSO

IRIX manpages for syssgi and nvram.

=cut

