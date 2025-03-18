create_snapshot()
facing = 0
function get_random_facing()
	facing = facing + 32
	if facing == 256 then 
		facing = 0
	end
	return facing
end

function get_random_move(x, y)
	local rnd = math.random()
	if rnd > 0.6 then
		x = x + math.random(-1,1)
	elseif rnd > 0.2 then
		y = y + math.random(-1,1)
	end
	return x, y
end

for j=0,50 do
	for i,a in pairs(get_infantries()) do
		if a.type == "DESO" then
			a:remove()
			a.status = "Unload"
			a:place()
		elseif a.type == "SHK" then
			a:remove()
			a.facing = tostring(get_random_facing())
			a:place()
		end
	end
	update_infantry()
	redraw_window()
	sleep(100)
	for i,a in pairs(get_infantries()) do
		if a.type == "DESO" then
			a:remove()
			a.facing = tostring(get_random_facing())
			a.status = "Guard"
			a.x, a.y = get_random_move(a.x, a.y)
			a:place()
		elseif a.type == "SHK" then
			a:remove()
			a.facing = tostring(get_random_facing())
			a.x, a.y = get_random_move(a.x, a.y)
			a:place()
		end
	end
	update_infantry()
	redraw_window()
	sleep(100)
	avoid_time_out()
end