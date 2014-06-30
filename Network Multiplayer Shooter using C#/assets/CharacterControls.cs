using UnityEngine;
using System.Collections;

[RequireComponent(typeof(CharacterController))]

public class CharacterControls : MonoBehaviour {
	public bool enableControls = false;

	public float speed = 10.0F;
	public float rotateSpeed =15.0F;

	void Update() {
				if (enableControls == true) {
						CharacterController controller = GetComponent<CharacterController> ();
						transform.Rotate (0, Input.GetAxis ("Horizontal") * rotateSpeed, 0);
						Vector3 forward = transform.TransformDirection (Vector3.forward);
						float curSpeed = speed * Input.GetAxis ("Vertical");
						controller.SimpleMove (forward * curSpeed);
				}
		}


}