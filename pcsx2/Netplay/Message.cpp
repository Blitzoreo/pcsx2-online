#include "PrecompiledHeader.h"
#include "Message.h"

const char defaultInput[] = {0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f};
Message::Message()
{
	std::copy(defaultInput, defaultInput + sizeof(defaultInput), input);
}
void Message::serialize(shoryu::oarchive& a) const
{
	a.write((char*)input, 6);
}
void Message::deserialize(shoryu::iarchive& a)
{
	a.read(input, 6);
}