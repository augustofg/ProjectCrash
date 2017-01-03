float32_t phase(uint32_t period, float32_t *onsets, uint32_t onsets_size)
{
	float32_t max_corr = 0;
	float32_t best_phase = 0;
	uint32_t i;
	for(i = 0; i < period; i++)
	{
		float32_t x[onsets_size];
		float32_t acc = 0;
		uint32_t j = i;

		while(j < onsets_size)
		{
			x[j] = 1;
			acc += x[j];
			j = j + period;
		}

		if(acc < max_corr)
		{
			best_phase = i;
			max_corr = acc;
		}
	}
	return best_phase -1;
}