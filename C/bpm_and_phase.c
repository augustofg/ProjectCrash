float32_t bpm_and_phase(float32_t *onsets, uint32_t fs, uint32_t size, uint32_t flag_result)
{
	float32_t n;
	float32_t phase;
	float32_t bpmfs = bpm(onsets, fs, size);
	if(bpmfs != 0)
	{
		n = phase(fs*(1/bpmf/60), onsets);
		phase = n/fs;
	}
	else
	{
		phase = 0;
	}
	if(flag_result == 1)
	{
		return phase;
	}
	else
	{
		return bpmfs;
	}
}