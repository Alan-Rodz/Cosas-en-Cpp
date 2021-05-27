void crearLps(vector<int>& vectorLPS, string patron)
{
	//len = longitud del ultimo prefijo-sufijo
	int len = 0, i = 1;

	//lps siempre inicia en 0
	vectorLPS[0] = 0;
	while (i < patron.size())
	{
		//Si ambos caracteres son el mismo hacemos lps[i] = len+1, len++, i++
		if (patron[i] == patron[len]) 
		{
			vectorLPS[i] = len + 1;
			len++;
			i++;
		}
		else 
		{
			//Regresamos hasta que len sea 0
			if (len != 0)
				len = vectorLPS[len - 1];

			//Si len ya es 0 entonces hacemos lps[i] = 0, i++
			else 
			{
				vectorLPS[i] = 0;
				i++;
			}
		}
	}
}

int strStr(string texto, string patron)
{
	int tamañoTexto = texto.size();
	int tamañoPatron = patron.size();
	if (tamañoPatron == 0) 
		return 0;
	if (tamañoTexto == 0) 
		return -1;

	//arreglo/vector lps 
	vector<int> lps(tamañoPatron); 
	crearLps(lps, patron);

	int i = 0, j = 0;

	while (i < tamañoTexto)
	{
		if (texto[i] == patron[j])
		{
			i++;
			j++;
		}

		//Cuando hay un error reseteamos a j y hacemos que vaya a lps[j-1]
		else
		{
			if (j != 0)
				j = lps[j - 1];
			
			//si j == 0 solo hacemos i++
			else
				i++;
		}

		//si j == m entonces tenemos el patron requerido
		if (j == tamañoPatron) 
			//i-j es el indice donde el patron empieza
			return i - j; 
	}
	return -1;
}

int main() 
{
	string s1 = "abxabcabcaby";
	string s2 = "abcaby";
	cout << strStr(s1, s2) << endl;
}
