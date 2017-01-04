void bpm_and_phase(int8_t *audio, float32_t *phase, float32_t *bpmfs) 
{
	float32_t n;
	int8_t onsets[1000];
	onsets[0] = 0;
	int8_t i, j;
	int8_t k = 0;


	for (i = 0; i < 32000; i++)
	{
		audio[i] = audio[i]*audio[i];
		if (i == 31 + 32*k)
		{
			for (j = 1; j < 32; j++)
			{
				audio[i] = audio[i] + audio[i-j];
			}
			onsets[k] = onsets[k] + audio[i];
			k += 1;
		}
	}

	for (i = 0; i < 999; i++)
	{
		onsets[i] = onsets[i+1] - onsets[i];
		if (onsets[i] < 0)
		{
			onsets[i] = 0;
		}
	}
	onsets[1000] = 0;

	// apply a low pass filter in array onsets at 12,5Hz

	*bpmfs = bpm(onsets, 250, 999);
	if(*bpmfs > 0.0000035)
	{
		n = phase(15000/(*bpmfs), onsets, 999);
		*phase = n/250;
	}
	else
	{
		*phase = 0;
	}
	
}