using UnityEngine;
using System.Collections;

public class CameraScript : MonoBehaviour {
	public Transform target;
		
	// Update is called once per frame
	void LateUpdate () {
		if (!target)
			return;
		Vector3 currentPosition = target.position;
		transform.position = currentPosition;
		Quaternion currentRotation = target.rotation;
		transform.rotation = currentRotation;
	}
}
