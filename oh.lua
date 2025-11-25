-- SCRIPT DÙNG CHO TẤT CẢ GAME BẠN TẠO
-- KEY BẢO MẬT: himn (KHÔNG HIỂN THỊ)

local Players = game:GetService("Players")
local UserInputService = game:GetService("UserInputService")
local player = Players.LocalPlayer

local ScreenGui = Instance.new("ScreenGui")
ScreenGui.Name = "UniversalSpeedGUI"
ScreenGui.Parent = player:WaitForChild("PlayerGui")

local function getHumanoid()
	local char = player.Character or player.CharacterAdded:Wait()
	return char:WaitForChild("Humanoid")
end

local humanoid = getHumanoid()

player.CharacterAdded:Connect(function()
	humanoid = getHumanoid()
end)

-- KEY
local SECRET_KEY = "himn"

-- KHUNG NHẬP KEY
local keyFrame = Instance.new("Frame", ScreenGui)
keyFrame.Size = UDim2.new(0.4,0,0.25,0)
keyFrame.Position = UDim2.new(0.3,0,0.35,0)
keyFrame.BackgroundColor3 = Color3.fromRGB(0,0,0)

local title = Instance.new("TextLabel", keyFrame)
title.Size = UDim2.new(1,0,0.3,0)
title.Text = "🔐 Nhập key để sử dụng"
title.TextColor3 = Color3.new(1,1,1)
title.BackgroundTransparency = 1
title.TextScaled = true

local keyBox = Instance.new("TextBox", keyFrame)
keyBox.Size = UDim2.new(0.9,0,0.3,0)
keyBox.Position = UDim2.new(0.05,0,0.35,0)
keyBox.PlaceholderText = "Nhập key..."
keyBox.BackgroundColor3 = Color3.fromRGB(20,20,20)
keyBox.TextColor3 = Color3.new(1,1,1)

local btn = Instance.new("TextButton", keyFrame)
btn.Size = UDim2.new(0.9,0,0.2,0)
btn.Position = UDim2.new(0.05,0,0.7,0)
btn.Text = "XÁC NHẬN"
btn.BackgroundColor3 = Color3.fromRGB(40,40,40)
btn.TextColor3 = Color3.new(1,1,1)

-- GUI CHÍNH
local mainFrame = Instance.new("Frame", ScreenGui)
mainFrame.Size = UDim2.new(0.5,0,0.25,0)
mainFrame.Position = UDim2.new(0.25,0,0.65,0)
mainFrame.BackgroundColor3 = Color3.fromRGB(0,0,0)
mainFrame.Visible = false

local status = Instance.new("TextLabel", mainFrame)
status.Size = UDim2.new(1,0,0.3,0)
status.Text = "✅ Đã hoàn thành"
status.TextColor3 = Color3.new(1,1,1)
status.BackgroundTransparency = 1
status.TextScaled = true

local bar = Instance.new("Frame", mainFrame)
bar.Size = UDim2.new(0.9,0,0.2,0)
bar.Position = UDim2.new(0.05,0,0.6,0)
bar.BackgroundColor3 = Color3.fromRGB(40,40,40)

local knob = Instance.new("Frame", bar)
knob.Size = UDim2.new(0,30,1,0)
knob.BackgroundColor3 = Color3.fromRGB(0,0,0)
knob.BorderColor3 = Color3.new(1,1,1)

-- XÁC NHẬN KEY
btn.MouseButton1Click:Connect(function()
	if keyBox.Text == SECRET_KEY then
		keyFrame.Visible = false
		mainFrame.Visible = true
	else
		title.Text = "❌ Sai key"
	end
end)

-- TỐC ĐỘ
local minSpeed = 5
local maxSpeed = 200
local dragging = false

local function setSpeed(x)
	local barSize = bar.AbsoluteSize.X
	local pos = math.clamp(x, 0, barSize - knob.AbsoluteSize.X)
	knob.Position = UDim2.new(0, pos, 0, 0)

	local percent = pos / (barSize - knob.AbsoluteSize.X)
	local speed = math.floor(minSpeed + (maxSpeed - minSpeed) * percent)

	humanoid.WalkSpeed = speed

	if speed < 40 then
		status.Text = "🐢 Bạn chạy quá chậm"
	elseif speed < 120 then
		status.Text = "✅ Tốc độ đã vừa đủ"
	else
		status.Text = "⚠️ Tốc độ đã vượt quá giới hạn"
	end
end

knob.InputBegan:Connect(function(input)
	if input.UserInputType == Enum.UserInputType.Touch or input.UserInputType == Enum.UserInputType.MouseButton1 then
		dragging = true
	end
end)

UserInputService.InputChanged:Connect(function(input)
	if dragging and (input.UserInputType == Enum.UserInputType.MouseMovement or input.UserInputType == Enum.UserInputType.Touch) then
		setSpeed(input.Position.X - bar.AbsolutePosition.X)
	end
end)

UserInputService.InputEnded:Connect(function()
	dragging = false
end)