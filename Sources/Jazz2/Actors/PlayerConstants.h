#pragma once

#include <algorithm>
#include <cmath>

namespace Jazz2::Actors
{
	/** @brief Centralized player speed/physics constants with a global speed factor for easy tuning */
	namespace PlayerConstants
	{
		/** Global speed multiplier applied to all player action speeds. Adjust this single value to uniformly scale all movement. */
		static constexpr float SpeedFactor = 1.0f;

		// Movement
		static constexpr float MaxDashingSpeed = 9.0f * SpeedFactor;
		static constexpr float MaxRunningSpeed = 4.0f * SpeedFactor;
		static constexpr float MaxVineSpeed = 2.0f * SpeedFactor;
		static constexpr float MaxDizzySpeed = 2.4f * SpeedFactor;
		static constexpr float MaxShallowWaterSpeed = 3.6f * SpeedFactor;
		static constexpr float Acceleration = 0.2f * SpeedFactor;
		static constexpr float Deceleration = 0.22f * SpeedFactor;

		// Gravity
		static constexpr float DefaultGravity = 0.3f;

		// Standard jump
		static constexpr float JumpSpeedReforged = -3.6f * SpeedFactor;
		static constexpr float JumpSpeedOriginal = -8.0f * SpeedFactor;
		static constexpr float JumpInternalForceReforged = -1.02f;
		static constexpr float JumpSpeedXThreshold = 4.0f;
		static constexpr float JumpSpeedXFactor = 0.3f;
		static constexpr float JumpTime = 10.0f;
		static constexpr float JumpReleaseCap = -4.0f * SpeedFactor;
		static constexpr float LoriJumpMultiplier = 1.3f;

		// Lift jump
		static constexpr float LiftJumpTime = 12.0f;
		static constexpr float LiftJumpSpeedY = -3.0f * SpeedFactor;
		static constexpr float LiftJumpInternalForceY = -0.88f * SpeedFactor;

		// Buttstomp
		static constexpr float ButtstompSpeedY = 9.0f * SpeedFactor;
		static constexpr float ButtstompMovementFactor = 0.2f;
		static constexpr float ButtstompRunMultiplier = 2.6f;

		// Jazz uppercut
		static constexpr float UppercutForceYReforged = -1.4f * SpeedFactor;
		static constexpr float UppercutForceYOriginal = -1.2f * SpeedFactor;
		static constexpr float UppercutSpeedY = -2.0f * SpeedFactor;

		// Copter
		static constexpr float CopterSpeedY = 1.5f;
		static constexpr float CopterFrames = 70.0f;
		static constexpr float CopterMaxFallSpeed = 1.5f;

		// Spaz sidekick
		static constexpr float SpazSidekickForceX = 8.0f * SpeedFactor;
		static constexpr float SpazSidekickSpeedX = 14.4f * SpeedFactor;
		static constexpr float SpazSidekickTimeout = 60.0f;

		// Spaz double jump
		static constexpr float SpazDoubleJumpForceReforged = -1.15f * SpeedFactor;
		static constexpr float SpazDoubleJumpForceOriginal = -0.88f * SpeedFactor;
		static constexpr float SpazDoubleJumpSpeedY = -0.6f * SpeedFactor;
		static constexpr float SpazDoubleJumpSpeedXDampen = 0.4f;
		static constexpr float SpazDoubleJumpSpeedXClamp = 1.0f;

		// Lori sidekick
		static constexpr float LoriSidekickForceX = 4.0f * SpeedFactor;
		static constexpr float LoriSidekickSpeedX = 9.3f * SpeedFactor;
		static constexpr float LoriSidekickTimeout = 40.0f;
	}
}
