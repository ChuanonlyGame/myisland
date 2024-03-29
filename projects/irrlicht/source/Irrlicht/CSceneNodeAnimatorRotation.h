// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __C_SCENE_NODE_ANIMATOR_ROTATION_H_INCLUDED__
#define __C_SCENE_NODE_ANIMATOR_ROTATION_H_INCLUDED__

#include "ISceneNode.h"

namespace irr
{
namespace scene
{
	class CSceneNodeAnimatorRotation : public ISceneNodeAnimator
	{
	public:

		//! constructor
		CSceneNodeAnimatorRotation(u32 time, const core::vector3df& rotation);

		//! animates a scene node
		virtual void animateNode(ISceneNode* node, u32 timeMs) _IRR_OVERRIDE_;

		//! Writes attributes of the scene node animator.
		virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options=0) const _IRR_OVERRIDE_;

		//! Reads attributes of the scene node animator.
		virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options=0) _IRR_OVERRIDE_;

		//! Returns type of the scene node animator
		virtual ESCENE_NODE_ANIMATOR_TYPE getType() const _IRR_OVERRIDE_ { return ESNAT_ROTATION; }

		//! Creates a clone of this animator.
		/** Please note that you will have to drop
		(IReferenceCounted::drop()) the returned pointer after calling this. */
		virtual ISceneNodeAnimator* createClone(ISceneNode* node, ISceneManager* newManager=0) _IRR_OVERRIDE_;
		
		//! Reset a time-based movement by changing the starttime. 
		virtual void setStartTime(u32 time) _IRR_OVERRIDE_
		{
			StartTime = time;
		}
		
		//! Get the starttime. 
		virtual irr::u32 getStartTime() const _IRR_OVERRIDE_
		{
			return StartTime;
		}

	private:

		core::vector3df Rotation;
		u32 StartTime;
	};


} // end namespace scene
} // end namespace irr

#endif

