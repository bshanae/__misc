using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(AudioSource))]
public class AudioManager : MonoBehaviour
{
	private AudioSource audioSource;
	private Dictionary<AudioClipName, AudioClip> audioClips;
	
    void Awake()
	{
		audioSource = GetComponent<AudioSource>();
		
		audioClips = new Dictionary<AudioClipName, AudioClip>();
		LoadWithSameName(AudioClipName.Explosion1);
		LoadWithSameName(AudioClipName.Explosion2);
		LoadWithSameName(AudioClipName.Explosion3);
		LoadWithSameName(AudioClipName.Laser);
		LoadWithSameName(AudioClipName.Death);
	}

	private void LoadWithSameName(AudioClipName name)
	{
		audioClips.Add(name, Resources.Load<AudioClip>("Sounds/" + name));
	}

	public void Play(AudioClipName name)
	{
		audioSource.PlayOneShot(audioClips[name]);
	}
	
}
