/**
 * _isupper - prints if characters are lowercase or uppercase
 * 0 lowercase 1 uppercase
 * @c: the character that is tested
 * Return: 0 lowercase, 1 uppercase
 */
int _isupper(int c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	else
		return (0);
}
