#pragma once

// STD INCLUDES

#include <map>
#include <vector>

//MY INCLUDES

#include <SDL.h>
#include <spdlog/spdlog.h>

#include "types.h"
#include "geometry/rect.h"
#include "render/backends/backend_types.h"

// Window should not outlive RendererBackend
class Window
{
private:
 // WINDOW PROPERTIES & INTERNALS
 const char* window_name_;
 SDL_Window* sdl_window_;
 SDL_Event event_;
 u32 window_id_;

 // old transform to check if updates need to be made to it's position and scale
 Geometry::Rect prev_transform_;

 // OTHER ATTRIBUTES
 bool requested_quit_{false};
 bool is_focused_{false};
 bool should_be_always_focused_{false};

 // CALLBACK DECLARATIONS
 void (*on_mouse_motion_)(int x, int y, int xrel, int yrel){nullptr};
 void (*on_mousebutton_down_)(int x, int y, Uint8 button){nullptr};
 void (*on_mousebutton_up)(int x, int y, Uint8 button){nullptr};
 void (*on_keydown_)(SDL_Keycode key, Uint16 modifier){nullptr};
 void (*on_keyup_)(SDL_Keycode key, Uint16 modifier){nullptr};

 // OTHER

 void UpdateTransform();

public:
 Window(const char* name, u32 x, u32 y, u16 w, u16 h, Render::BackendType render_backend_type);
 ~Window();

 void Update();
 void Clear();
 void Clear(f32 r, f32 g, f32 b, f32 a);

 // public attributes
 // transform of the window
 Geometry::Rect transform;

 inline bool requested_quit()
 {
  return requested_quit_;
 };

 // Accessors and other attributes
 inline SDL_Window* sdl_window()
 {
  return sdl_window_;
 }
 inline u32 window_id() const
 {
  return window_id_;
 }

 inline u16 width() const
 {
  return transform.w;
 }
 inline u16 height() const
 {
  return transform.h;
 }
 inline void UpdateWindowFocusStatus(bool is_focused)
 {
  is_focused_ = is_focused;
 }

 // Convenience methods
 inline void CaptureMouse(bool capture) const
 {
  SDL_SetWindowGrab(sdl_window_, capture ? SDL_TRUE : SDL_FALSE);
 }
 inline void AlwaysOnTop(bool always_on_top) const
 {
  SDL_SetWindowAlwaysOnTop(sdl_window_, always_on_top ? SDL_TRUE : SDL_FALSE);
 }
 // this will attempt to steal input focus back to the window every update.
 // doesn't work right now for some reason
 inline void AlwaysFocused(bool focused)
 {
  should_be_always_focused_ = focused;
 }

 //TODO! replace with event architecture thing.

 /* PARAMS:
  * int x: abs
  * int y: abs
  * int xrel: relative
  * int yrel: relative */
 void SetMouseMotionCallback(void (*callback)(int x, int y, int xrel, int yrel));
 /* PARAMS:
  * int x: abs
  * int y: abs
  * Uint8 button (could either be SDL_BUTTON_RIGHT or SDL_BUTTON_LEFT*/
 void SetMouseButtonDownCallback(void (*callback)(int x, int y, Uint8 button));
 /* PARAMS:
  * int x: abs
  * int y: abs
  * Uint8 button (could either be SDL_BUTTON_RIGHT or SDL_BUTTON_LEFT*/
 void SetMouseButtonUpCallback(void (*callback)(int x, int y, Uint8 button));
 /* PARAMS:
  * SDL_Keycode key: the SDL_Keycode representing the pressed key
  * Uint16 modifier: the modifier flags (e.g., ctrl is down, win is down...)
  */
 void SetKeyDownCallback(void (*callback)(SDL_Keycode key, Uint16 modifier));

 /* PARAMS:
  * SDL_Keycode key: the SDL_Keycode representing the released key
  * Uint16 modifier: the modifier flags (e.g., ctrl is down, win is down...)
  */
 void SetKeyUpCallback(void (*callback)(SDL_Keycode key, Uint16 modifier));

};

